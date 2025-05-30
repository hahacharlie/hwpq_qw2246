#!/bin/bash

# Get the current directory where the script is running
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
# Go up one level to the project root
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

# Check if exactly one argument is provided
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <architecture_name>"
  exit 1
fi

# Get the architecture name from the first argument
ARCHITECTURE_NAME=$1

# Create directories for logs
mkdir -p parallel_logs

ENQ_ENA_VALUES=(0 1)

# Define sweep range of queue size based on architecture name
# tip 0 - if you want to increase the upper bound, try it in Vivado first to see if it's even possible
if [[ "$ARCHITECTURE_NAME" == *"tree"* ]]; then
  QUEUE_SIZE_VALUES=(3 7 15 31 63 127 255 511 1023 2047)
  echo "Architecture name '$ARCHITECTURE_NAME' contains 'tree'. Using odd queue sizes."
elif [[ "$ARCHITECTURE_NAME" == *"array"* ]]; then
  QUEUE_SIZE_VALUES=(4 8 16 32 64 128 256 512 1024 2048)
  echo "Architecture name '$ARCHITECTURE_NAME' contains 'array'. Using even queue sizes."
else
  echo "Error: Architecture name '$ARCHITECTURE_NAME' must contain either 'tree' or 'array'."
  exit 1
fi

# Set results and tcl scipts directory based on architecture name
RESULTS_DIR="$PROJECT_ROOT/hwpq/${ARCHITECTURE_NAME}/vivado_analysis_results_16bit_xcau25p"
SYNTH_SCRIPT="$PROJECT_ROOT/vivado-synthesis_tcl/synth_design_param_sweep_parallel.tcl"

# NOTE - Set the maximum number of parallel jobs - change accordingly
MAX_PARALLEL=2

# Create a temporary directory for job tracking
JOB_TRACK_DIR=$(mktemp -d)
echo "Using temporary directory for job tracking: $JOB_TRACK_DIR"
echo " "

# Create a directory for each enq_ena value
for enq_ena in "${ENQ_ENA_VALUES[@]}"; do
  mkdir -p "${RESULTS_DIR}/enqueue_${enq_ena}"
done

# Cleanup function to remove temporary files on exit
cleanup() {
  echo "Cleaning up temporary files..."
  echo " "
  rm -rf "$JOB_TRACK_DIR"
}
trap cleanup EXIT

# Function to mark a job as running
start_job() {
  local job_name=$1
  touch "$JOB_TRACK_DIR/$job_name"
}

# Function to mark a job as completed
complete_job() {
  local job_name=$1
  rm -f "$JOB_TRACK_DIR/$job_name"
}

# Function to check if a job is running
is_job_running() {
  local job_name=$1
  [ -f "$JOB_TRACK_DIR/$job_name" ]
  return $?
}

# Function to get the current number of running jobs
get_running_jobs_count() {
  find "$JOB_TRACK_DIR" -type f | wc -l
}

# Function to list all running jobs
list_running_jobs() {
  for job_file in "$JOB_TRACK_DIR"/*; do
    if [ -f "$job_file" ]; then
      basename "$job_file"
    fi
  done
}

# Function to check if a job has completed by examining its log file
job_is_completed() {
  local job_name=$1
  local log_file="parallel_logs/vivado_${job_name}.log"
  
  # Check if log file exists
  if [ ! -f "$log_file" ]; then
    return 1  # Job not completed (log doesn't exist)
  fi
  
  # Check if the log file contains the completion message
  if grep -q "Analysis completed for ENQ" "$log_file"; then
    return 0  # Job is complete
  else
    return 1  # Job still running
  fi
}

# Function to print current job status
print_job_status() {
  local job_count=$(get_running_jobs_count)
  
  echo " "
  echo "=== Current Job Status ==="
  echo "Running jobs: $job_count of $MAX_PARALLEL"
  
  if [ "$job_count" -gt 0 ]; then
    echo "Job list:"
    list_running_jobs | while read job; do
      echo "  - $job"
    done
  else
    echo "No jobs currently running."
  fi
  echo "========================="
  echo " "
}

# Function to check if we can start another job
can_start_job() {
  # First check for completed jobs and remove them
  for job_file in "$JOB_TRACK_DIR"/*; do
    if [ -f "$job_file" ]; then
      local job_name=$(basename "$job_file")
      if job_is_completed "$job_name"; then
        echo "Job $job_name has completed"
        echo " "
        complete_job "$job_name"
      fi
    fi
  done
  
  # Now check if we're below the MAX_PARALLEL limit
  local job_count=$(get_running_jobs_count)
  if [ "$job_count" -lt "$MAX_PARALLEL" ]; then
    return 0  # Yes, we can start a job
  else
    return 1  # No slots available
  fi
}

# Function to wait for at least one job to complete
wait_for_job() {
  echo "Waiting for a job to complete..."
  print_job_status
  
  while true; do
    for job_file in "$JOB_TRACK_DIR"/*; do
      if [ -f "$job_file" ]; then
        local job_name=$(basename "$job_file")
        if job_is_completed "$job_name"; then
          echo "Job $job_name has completed"
          echo " "
          complete_job "$job_name"
          return
        fi
      fi
    done
    sleep 10  # Check every 10 seconds
  done
}

# Process all parameter combinations
for enq_ena in "${ENQ_ENA_VALUES[@]}"; do
  for queue_size in "${QUEUE_SIZE_VALUES[@]}"; do
    job_name="ENQ${enq_ena}_QS${queue_size}"
    log_file="parallel_logs/vivado_${job_name}.log"
    result_file="${RESULTS_DIR}/enqueue_${enq_ena}/vivado_analysis_on_queue_size_${queue_size}.txt"
    
    # Check if job is already running
    if is_job_running "$job_name"; then
      echo "WARNING: Job $job_name is already running. Skipping duplicate."
      echo " "
      continue
    fi
    
    # Check if the result file already exists and contains results
    if [ -f "$result_file" ] && grep -q "Analysis completed for ENQ" "$result_file"; then
      echo "Job $job_name already completed (result file exists). Skipping."
      echo " "
      continue
    fi
    
    # Wait until we can start a new job
    while ! can_start_job; do
      echo "Maximum parallel jobs ($MAX_PARALLEL) running. Waiting for a job slot..."
      echo " "
      wait_for_job
    done
    
    echo "Starting Vivado job for ${job_name}..."
    vivado -mode batch -nolog -nojournal -source $SYNTH_SCRIPT -tclargs $ARCHITECTURE_NAME $enq_ena 16 $queue_size > "$log_file" 2>&1 &
    
    # Mark job as running
    start_job "$job_name"
    
    echo "Started job for ${job_name}"
    echo "Currently running jobs: $(get_running_jobs_count) of $MAX_PARALLEL"
    echo " "
    print_job_status
    
    # Small delay to prevent overwhelming the system
    sleep 2
  done
done

# Wait for all remaining jobs to complete
echo "Waiting for all remaining jobs to complete..."
while [ "$(get_running_jobs_count)" -gt 0 ]; do
  for job_file in "$JOB_TRACK_DIR"/*; do
    if [ -f "$job_file" ]; then
      job_name=$(basename "$job_file")
      if job_is_completed "$job_name"; then
        echo "Job $job_name has completed"
        echo " "
        complete_job "$job_name"
      fi
    fi
  done
  
  # local remaining=$(get_running_jobs_count)
  # if [ "$remaining" -gt 0 ]; then
  #   echo "Still waiting for $remaining jobs to complete..."
  #   print_job_status
  #   sleep 30
  # fi
done

echo "All parameter sweep jobs have completed successfully!"

# Optional: Generate a summary of results
# echo "Generating summary of results..."

# Create header for the summary file
# summary_file="${RESULTS_DIR}/all_results_summary.csv"
# echo "ENQ_ENA,QUEUE_SIZE,MAX_FREQ_MHZ,WNS,CLB_LUTS,CLB_REGS,BRAM,POWER_W" > "$summary_file"

# Process result files to extract the maximum frequency achieved for each configuration
# for enq_ena in "${ENQ_ENA_VALUES[@]}"; do
#   for queue_size in "${QUEUE_SIZE_VALUES[@]}"; do
#     result_file="${RESULTS_DIR}/enqueue_${enq_ena}/vivado_analysis_on_queue_size_${queue_size}.txt"
    
#     if [ -f "$result_file" ]; then
#       # Extract the last clock frequency that passed timing
#       last_freq=$(grep -B 1 "WNS exceeded -1 ns" "$result_file" | grep "Frequency:" | tail -1 | awk '{print $2}' || \
#                   grep "Frequency:" "$result_file" | tail -1 | awk '{print $2}')
#       last_wns=$(grep "WNS:" "$result_file" | tail -1 | awk '{print $4}')
#       last_luts=$(grep "CLB LUTs Used:" "$result_file" | tail -1 | awk '{print $5}')
#       last_regs=$(grep "CLB Registers Used:" "$result_file" | tail -1 | awk '{print $5}')
#       last_bram=$(grep "BRAM Util:" "$result_file" | tail -1 | awk '{print $4}')
#       last_power=$(grep "Power:" "$result_file" | tail -1 | awk '{print $4}')
      
#       # Add to summary file
#       echo "${enq_ena},${queue_size},${last_freq},${last_wns},${last_luts},${last_regs},${last_bram},${last_power}" >> "$summary_file"
#     else
#       echo "Warning: Result file not found for ENQ_ENA=${enq_ena}, QUEUE_SIZE=${queue_size}"
#     fi
#   done
# done

# echo "Parameter sweep completed. Results saved and summarized."