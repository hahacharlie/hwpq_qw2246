# Define the range of TREE_DEPTH and clock frequencies to test
# Use the first list for any array-liked architectures
# Use the second list for any tree-liked architectures
set queue_sizes {4 8 16 32 64 128 256 512}
# set queue_sizes {3 7 15 31 63 127 255 511 1023 2047 4095 8191 16383 32767 65535 131071 262143 524287}

set enq_flags 1

# NOTE Change according to the module running analysis
file mkdir ./RegisterArray/vivado_analysis_results_16bit_cycled/enqueue_0/
file mkdir ./RegisterArray/vivado_analysis_results_16bit_cycled/enqueue_1/

foreach enq_flag $enq_flags {
  # NOTE Change according to the module running analysis
  set file_id [open "./RegisterArray/rtl/RegisterArray_Cycled.sv" r+]

  # Read the file content and ensure it's cleaned
  set file_content [string trim [read $file_id]]

  # Replace the parameter ENQUEUE value - ensure clean replacement
  set updated_content [regsub {parameter bit ENQ_ENA = \d+} $file_content "parameter bit ENQ_ENA = $enq_flag"]

  # Clean any potential garbage characters
  set updated_content [regsub -all {[^[:print:]\n\r\t]} $updated_content ""]

  # Rewind the file pointer to the beginning
  seek $file_id 0

  # Ensure content ends with exactly one newline and no trailing characters
  set updated_content [string trimright $updated_content]
  set updated_content "${updated_content}\n"
  
  # Write the updated content back to the file
  puts -nonewline $file_id $updated_content

  # Close the file
  close $file_id

  # Loop through each QUEUE_SIZE
  foreach queue_size $queue_sizes {
    # NOTE Change according to the module running analysis
    set file_id [open "./RegisterArray/rtl/RegisterArray_Cycled.sv" r+]

    # Read the file content and ensure it's cleaned
    set file_content [string trim [read $file_id]]

    # Replace the parameter QUEUE_SIZE value - ensure clean replacement
    set updated_content [regsub {parameter int QUEUE_SIZE = \d+} $file_content "parameter int QUEUE_SIZE = $queue_size"]

    # Clean any potential garbage characters
    set updated_content [regsub -all {[^[:print:]\n\r\t]} $updated_content ""]

    # Rewind the file pointer to the beginning
    seek $file_id 0

    # Ensure content ends with exactly one newline and no trailing characters
    set updated_content [string trimright $updated_content]
    set updated_content "${updated_content}\n"
    
    # Write the updated content back to the file
    puts -nonewline $file_id $updated_content

    # Close the file
    close $file_id

    # NOTE - Change according to the module running analysis
    set log_file "./RegisterArray/vivado_analysis_results_16bit_cycled/enqueue_${enq_flag}/vivado_analysis_on_queue_size_${queue_size}.txt"

    # Loop through each frequency
    for {set freq 100} {$freq <= 800} {incr freq 50} {

      # NOTE Change according to the module running analysis
      open_project ./RegisterArray/RegisterArray-vivado/RegisterArray-vivado.xpr

      # Set max threads
      set_param general.maxThreads 24

      # Set the clock period (in nanoseconds)
      set period_ns [expr {1000.0 / $freq}]

      # Reset the previous synthesis result
      reset_run synth_1

      # Start a new synthesis and time how long it takes
      set synth_start_time [clock seconds]
      launch_runs synth_1
      wait_on_run -timeout 30 synth_1

      # Check if synthesis completed successfully
      if {[get_property PROGRESS [get_runs synth_1]] != "100%"} {
        set fileId [open $log_file "a+"]
        puts $fileId "Frequency: ${freq} MHz -> Synthesis did not complete successfully in 30 minutes"
        close $fileId
        reset_run synth_1
        close_project
        break 2
      }

      set synth_end_time [clock seconds]

      # Calculate the synthesis duration
      set synth_duration [expr $synth_end_time - $synth_start_time]
      if {$synth_duration > 60} {
        set minutes [expr int($synth_duration / 60)]
        set seconds [expr $synth_duration % 60]
        set synth_duration_str "${minutes}m ${seconds}s"
      } else {
        set synth_duration_str "${synth_duration}s"
      }

      # Open the synthesis result
      open_run synth_1

      # Create a timing constraint
      create_clock -name sys_clk -period $period_ns [get_ports i_CLK]

      # Reset the previous implementation result
      reset_run impl_1

      # Start a new implementation run and time how long it takes
      set impl_start_time [clock seconds]
      launch_runs impl_1
      wait_on_run -timeout 30 impl_1

      # Check if implementation completed successfully
      if {[get_property PROGRESS [get_runs impl_1]] != "100%"} {
        set fileId [open $log_file "a+"]
        puts $fileId "Frequency: ${freq} MHz -> Implementation did not complete successfully in 30 minutes"
        close $fileId
        reset_run synth_1
        reset_run impl_1
        close_project
        break 2
      }

      set impl_end_time [clock seconds]

      # Calculate the implementation duration
      set impl_duration [expr $impl_end_time - $impl_start_time]
      if {$impl_duration > 60} {
        set minutes [expr int($impl_duration / 60)]
        set seconds [expr $impl_duration % 60]
        set impl_duration_str "${minutes}m ${seconds}s"
      } else {
        set impl_duration_str "${impl_duration}s"
      }

      # Open the implementation result
      open_run impl_1

      # Extract the utilization report content
      set utilization_report [report_utilization -return_string]

      # Extract the Util% of CLB LUTs and CLB Registers from the report
      set in_section_1 0
      foreach line [split $utilization_report "\n"] {
        if {[regexp {^1\. CLB Logic} $line]} {
          set in_section_1 1
        } elseif {[regexp {^\d+\.} $line]} {
          set in_section_1 0
        }

        if {$in_section_1} {
          if {[regexp {\|\s*CLB LUTs\s*\|\s*([0-9]+)\s*\|\s*[0-9]+\s*\|\s*[0-9]+\s*\|\s*[0-9]+\s*\|\s*([0-9]+\.[0-9]+)\s*\|} $line match luts_used luts_util]} {
            set clb_luts_used $luts_used
            set clb_luts_util $luts_util
          }
          if {[regexp {\|\s*CLB Registers\s*\|\s*([0-9]+)\s*\|\s*[0-9]+\s*\|\s*[0-9]+\s*\|\s*[0-9]+\s*\|\s*([0-9]+\.[0-9]+)\s*\|} $line match registers_used registers_util]} {
            set clb_registers_used $registers_used
            set clb_registers_util $registers_util
          }
        }
      }

      # Extract the Util% of Block RAMs from the report
      set in_section_3 0
      foreach line [split $utilization_report "\n"] {
        if {[regexp {^3\. BLOCKRAM} $line]} {
          set in_section_3 1
        } elseif {[regexp {^\d+\.} $line]} {
          set in_section_3 0
        }

        if {$in_section_3} {
          if {[regexp {\|\s*Block RAM Tile\s*\|\s*([0-9]+\.?[0-9]*)\s*\|\s*[0-9]+\s*\|\s*[0-9]+\s*\|\s*[0-9]+\s*\|\s*([0-9]+\.[0-9]+)\s*\|} $line match bram_util bram_util_percent]} {
            set bram_used $bram_util
            set bram_util_percentage $bram_util_percent
          }
        }
      }

      # Report power summary and get the total on-chip power
      set power_report [report_power -return_string]
      set match [regexp {\|\s*Total On-Chip Power \(W\)\s*\|\s*([0-9\.]+)\s*\|} $power_report full_match total_on_chip_power]

      # Report timing summary and get the Worst Negative Slack (WNS)
      set timing_report [report_timing_summary -delay_type max -significant_digits 3]

      # Extract WNS from the timing summary
      set wns [get_property SLACK [get_timing_paths]]

      # Calculate the achieved frequency using WNS and target frequency with 3 significant digits
      set achieved_frequency [format "%.3f" [expr {1000.0 / ($period_ns - $wns)}]]

      set fileId [open $log_file "a+"]

      # Print the results to the log file
      puts $fileId "Frequency: ${freq} MHz -> Synthesis: ${synth_duration_str} -> ${synth_duration}s"
      puts $fileId "Frequency: ${freq} MHz -> Implementation: ${impl_duration_str} -> ${impl_duration}s"
      if ($match) {
        puts $fileId "Frequency: ${freq} MHz -> Power: ${total_on_chip_power} W"
      } else {
        puts $fileId "Frequency: ${freq} MHz -> Power: No power report"
      }
      puts $fileId "Frequency: ${freq} MHz -> CLB LUTs Used: ${clb_luts_used}"
      puts $fileId "Frequency: ${freq} MHz -> CLB LUTs Util%: ${clb_luts_util} %"
      puts $fileId "Frequency: ${freq} MHz -> CLB Registers Used: ${clb_registers_used}"
      puts $fileId "Frequency: ${freq} MHz -> CLB Registers Util%: ${clb_registers_util} %"
      puts $fileId "Frequency: ${freq} MHz -> BRAM Util: ${bram_used}"
      puts $fileId "Frequency: ${freq} MHz -> BRAM Util%: ${bram_util_percentage} %"
      puts $fileId "Frequency: ${freq} MHz -> WNS: ${wns} ns"
      puts $fileId "Frequency: ${freq} MHz -> Achieved Frequency: ${achieved_frequency} MHz"
      puts $fileId "\n"

      # Break the frequency loop if WNS is less than -1 ns or resource utilization exceeded threshold
      if {$wns < -1.0} {
        puts $fileId "WNS exceeded -1 ns, finished\n"
        close $fileId
        close_project
        break
      } 

      close $fileId
      close_project
    }
  }
}


# NOTE Change according to the module running analysis
set file_id [open "./RegisterArray/rtl/RegisterArray_Cycled.sv" r+]

# Read the file content and ensure it's cleaned
set file_content [string trim [read $file_id]]

# Replace the parameter TREE_DEPTH value back to minimum - ensure clean replacement
set updated_content [regsub {parameter int QUEUE_SIZE = \d+} $file_content "parameter int QUEUE_SIZE = [lindex $queue_sizes 0]"]

# Clean any potential garbage characters
set updated_content [regsub -all {[^[:print:]\n\r\t]} $updated_content ""]

# Rewind the file pointer to the beginning
seek $file_id 0

# Ensure content ends with exactly one newline and no trailing characters
set updated_content [string trimright $updated_content]
set updated_content "${updated_content}\n"

# Write the updated content back to the file
puts -nonewline $file_id $updated_content

# Close the file
close $file_id
