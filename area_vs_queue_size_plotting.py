import os
import matplotlib.pyplot as plt

# import numpy as np

plt.rcParams.update({"font.size": 16})


def parse_area_utilization(file_path):
    """
    Parses a log file to extract frequencies and their corresponding LUTs Utilization.

    Args:
        file_path (str): The path to the log file.

    Returns:
        dict: A dictionary where keys are frequencies and values are LUTs Utilization.

    Example:
        Given a log file with the following content:
            Frequency: 150 MHz -> LUTs Util%: 0.07 %
            Frequency: 160 MHz -> LUTs Util%: 0.08 %

        The function will return:
            {150.0: 0.07, 160.0: 0.08}
    """
    utilization_data = {}

    with open(file_path, "r") as file:
        for line in file:
            if "Frequency" in line and "LUTs Util%" in line:
                parts = line.split("->")
                frequency = float(parts[0].split(":")[1].strip().split(" ")[0])
                utilization = float(parts[1].strip().split(" ")[2])
                utilization_data[frequency] = utilization

    return utilization_data


# Function to process log files in a directory
def process_register_array_log_directory(log_dir):
    """
    Processes log files in the given directory and returns a dictionary of data.
    """
    data = {}
    for file_name in sorted(
        os.listdir(log_dir), key=lambda x: int(x.split("_")[-1].split(".")[0])
    ):
        if file_name.startswith("vivado_analysis_on_queue_size") and file_name.endswith(
            ".txt"
        ):
            queue_size = int(file_name.split("_")[-1].split(".")[0])
            file_path = os.path.join(log_dir, file_name)
            area_utilization = parse_area_utilization(file_path)
            data[queue_size] = area_utilization
    return data


# Function to process log files in a directory
def process_register_tree_log_directory(log_dir):
    """
    Processes log files in the given directory and returns a dictionary of data.
    """
    data = {}
    for file_name in sorted(
        os.listdir(log_dir), key=lambda x: int(x.split("_")[-1].split(".")[0])
    ):
        if file_name.startswith("vivado_analysis_on_queue_size") and file_name.endswith(
            ".txt"
        ):
            queue_size = int(file_name.split("_")[-1].split(".")[0])
            file_path = os.path.join(log_dir, file_name)
            area_utilization = parse_area_utilization(file_path)
            data[queue_size] = area_utilization
    return data


# Function to process log files in a directory
def process_systolic_array_log_directory(log_dir):
    """
    Processes log files in the given directory and returns a dictionary of data.
    """
    data = {}
    for file_name in sorted(
        os.listdir(log_dir), key=lambda x: int(x.split("_")[-1].split(".")[0])
    ):
        if file_name.startswith("vivado_analysis_on_queue_size") and file_name.endswith(
            ".txt"
        ):
            queue_size = int(file_name.split("_")[-1].split(".")[0])
            file_path = os.path.join(log_dir, file_name)
            area_utilization = parse_area_utilization(file_path)
            data[queue_size] = area_utilization
    return data


# Define log directories for both register array and register tree
register_array_log_dir = "register_array/vivado_register_array_analysis_results_16bit/"
register_tree_log_dir = "register_tree/vivado_register_tree_analysis_results_16bit/"
systolic_array_log_dir = "systolic_array/vivado_systolic_array_analysis_results_16bit/"

# Process log files for register array
all_data_array = process_register_array_log_directory(register_array_log_dir)

# Process log files for register tree
all_data_tree = process_register_tree_log_directory(register_tree_log_dir)

# Process log files for register tree
all_data_systolic = process_systolic_array_log_directory(systolic_array_log_dir)

# Calculate final achieved frequencies for register array
final_area_utilization_register_array = {}
for queue_size, area_utilization in all_data_array.items():
    average_area_utilization = sum(area_utilization.values()) / len(area_utilization)
    final_area_utilization_register_array[queue_size] = average_area_utilization

# Calculate final achieved frequencies for register tree
final_area_utilization_register_tree = {}
for queue_size, area_utilization in all_data_tree.items():
    average_area_utilization = sum(area_utilization.values()) / len(area_utilization)
    final_area_utilization_register_tree[queue_size] = average_area_utilization

# Calculate final achieved frequencies for systolic array
final_area_utilization_systolic_array = {}
for queue_size, area_utilization in all_data_systolic.items():
    average_area_utilization = sum(area_utilization.values()) / len(area_utilization)
    final_area_utilization_systolic_array[queue_size] = average_area_utilization

# Plot the final achieved frequencies for both register array and register tree together
plt.figure(figsize=(10, 6))

# Plot for Systolic Array
queue_sizes_systolic_array = [
    int(size) for size in final_area_utilization_systolic_array.keys()
]
final_area_utilization_systolic_array = [
    value * 0.01 * 4085760
    for value in final_area_utilization_systolic_array.values()  # since value is in percentage
]
plt.plot(
    queue_sizes_systolic_array,
    final_area_utilization_systolic_array,
    marker="d",
    label="Systolic Array",
)

# Plot for register array
queue_sizes_register_array = [
    int(size) for size in final_area_utilization_register_array.keys()
]
final_area_utilization_register_array = [
    value * 0.01 * 4085760 for value in final_area_utilization_register_array.values()
]
plt.plot(
    queue_sizes_register_array,
    final_area_utilization_register_array,
    marker="o",
    label="Register Array",
)

# Plot for register tree
queue_sizes_register_tree = [
    int(size) for size in final_area_utilization_register_tree.keys()
]
final_area_utilization_register_tree = [
    value * 0.01 * 4085760 for value in final_area_utilization_register_tree.values()
]
plt.plot(
    queue_sizes_register_tree,
    final_area_utilization_register_tree,
    marker="x",
    label="Register Tree",
)

plt.xlabel("Queue Size", fontsize=20)
plt.ylabel("LUT Utilization", fontsize=20)

plt.xscale("log", base=2)
plt.yscale("log")

# Set axis ticks manually
# plt.xticks([4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048])
# plt.yticks([1000, 10000, 100000, 1000000])

plt.title("LUT Utilization vs QUEUE_SIZE")
plt.legend()
plt.grid(True)
plt.tight_layout()

output_dir = "vivado_analysis_results_plots_16bit"
os.makedirs(output_dir, exist_ok=True)
plt.savefig(os.path.join(output_dir, "final_area_utilization_plotting.pdf"))
