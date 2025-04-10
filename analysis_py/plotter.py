"""
Plotting functions for hardware queue performance analysis.
"""

import os
from datetime import datetime
import matplotlib.pyplot as plt
import parsers
import data_processor as dp
from config import OUTPUT_DIR

# Define consistent architecture styles
ARCHITECTURE_STYLES = {
    "register_array_enq_disabled": {
        "color": "darkblue",
        "marker": "o",
        "display_name": "Register Array (Enqueue Disabled)",
    },
    "register_array_enq_enabled": {
        "color": "royalblue",
        "marker": ".",
        "display_name": "Register Array (Enqueue Enabled)",
    },
    "register_array_cycled_enq_disabled": {
        "color": "cyan",
        "marker": "x",
        "display_name": "Register Array Cycled (Enqueue Disabled)",
    },
    "register_array_cycled_enq_enabled": {
        "color": "teal",
        "marker": "+",
        "display_name": "Register Array Cycled (Enqueue Enabled)",
    },
    "SystolicArray": {
        "color": "lime",
        "marker": "^",
        "display_name": "Systolic Array",
    },
    "register_tree_enq_disabled": {
        "color": "lightcoral",
        "marker": "8", 
        "display_name": "Register Tree (Enqueue Disabled)",
    },
    "register_tree_enq_enabled": {
        "color": "maroon",
        "marker": "p", 
        "display_name": "Register Tree (Enqueue Enabled)",
    },
    "bram_tree": {
        "color": "violet",
        "marker": "s", 
        "display_name": "BRAM Tree"
    },
    "pipelined_bram_tree": {
        "color": "slategray",
        "marker": "D",
        "display_name": "Pipelined BRAM Tree",
    },
    "hybrid_tree": {
        "color": "orange", 
        "marker": "d", 
        "display_name": "Hybrid Tree"
    },
}


def get_arch_style(arch_name):
    """
    Get the plotting style for a specific architecture.

    Args:
        arch_name (str): Architecture name (key in ARCHITECTURE_STYLES)

    Returns:
        dict: Style dictionary with color, marker, and display_name
    """
    # Try to find exact match first
    if arch_name in ARCHITECTURE_STYLES:
        return ARCHITECTURE_STYLES[arch_name]

    # Try to find a partial match (e.g., if arch_name contains a key)
    for key, style in ARCHITECTURE_STYLES.items():
        if key in arch_name or arch_name in key:
            return style

    # Default style if no match found
    return {
        "color": "gray",
        "marker": ".",
        "display_name": arch_name.replace("_", " ").title(),
    }


def setup_plot_style(
    font_size=None, figsize=None, dpi=None, grid=None, grid_alpha=None
):
    """
    Configure plot style settings for better readability.

    Args:
        font_size (int, optional): Base font size. Defaults to PLOT_FONT_SIZE.
        figsize (tuple, optional): Figure size as (width, height). Defaults to (12, 8).
        dpi (int, optional): Figure resolution in dots per inch. Defaults to 300.
        grid (bool, optional): Whether to show grid lines. Defaults to True.
        grid_alpha (float, optional): Transparency of grid lines (0-1). Defaults to 0.3.
    """
    params = {
        "font.size": font_size if font_size is not None else 16,
        "figure.figsize": figsize if figsize is not None else (12, 8),
        "figure.dpi": dpi if dpi is not None else 300,
        "axes.grid": grid if grid is not None else True,
        "grid.alpha": grid_alpha if grid_alpha is not None else 0.3,
    }
    plt.rcParams.update(params)


def plot_frequency_vs_queue_size(ax, data_dict, title=None, arch_name=None):
    """
    Plot the maximum achieved frequency vs queue size.

    Args:
        ax (matplotlib.axes.Axes): The axes to plot on
        data_dict (dict): Data from parsers.process_directory
        title (str, optional): Custom title for the plot
        arch_name (str, optional): Architecture name to determine plot style
    """
    queue_sizes, frequencies = dp.get_max_achieved_frequency(data_dict)

    # Get architecture-specific style
    style = (
        get_arch_style(arch_name)
        if arch_name
        else {"color": "blue", "marker": "o", "display_name": "Architecture"}
    )

    ax.plot(
        queue_sizes,
        frequencies,
        f"{style['marker']}-",
        color=style["color"],
        linewidth=2,
        label=style["display_name"],
    )

    ax.set_xlabel("Queue Size")
    ax.set_ylabel("Maximum Achieved Frequency (MHz)")
    ax.set_title(title or "Maximum Achieved Frequency vs Queue Size")
    ax.set_xscale("log", base=2)
    ax.grid(True)

    # Add legend if plotting multiple architectures
    if arch_name:
        ax.legend(fontsize=12)


def plot_lut_usage_vs_queue_size(ax, data_dict, title=None, arch_name=None):
    """
    Plot LUT usage vs queue size.

    Args:
        ax (matplotlib.axes.Axes): The axes to plot on
        data_dict (dict): Data from parsers.process_directory
        title (str, optional): Custom title for the plot
        arch_name (str, optional): Architecture name to determine plot style
    """
    queue_sizes, luts = dp.get_lut_usage(data_dict)

    # Get architecture-specific style
    style = (
        get_arch_style(arch_name)
        if arch_name
        else {"color": "red", "marker": "s", "display_name": "Architecture"}
    )

    ax.plot(
        queue_sizes,
        luts,
        f"{style['marker']}-",
        color=style["color"],
        linewidth=2,
        label=style["display_name"],
    )

    ax.set_xlabel("Queue Size")
    ax.set_ylabel("LUT Usage (Count)")
    ax.set_title(title or "LUT Usage vs Queue Size")
    ax.set_xscale("log", base=2)
    ax.grid(True)

    # Add legend if plotting multiple architectures
    if arch_name:
        ax.legend(fontsize=12)


def plot_lut_utilization_vs_queue_size(ax, data_dict, title=None, arch_name=None):
    """
    Plot LUT utilization percentage vs queue size.

    Args:
        ax (matplotlib.axes.Axes): The axes to plot on
        data_dict (dict): Data from parsers.process_directory
        title (str, optional): Custom title for the plot
        arch_name (str, optional): Architecture name to determine plot style
    """
    queue_sizes, lut_percentages = dp.get_lut_utilization(data_dict)

    # Get architecture-specific style
    style = (
        get_arch_style(arch_name)
        if arch_name
        else {"color": "green", "marker": "d", "display_name": "Architecture"}
    )

    ax.plot(
        queue_sizes,
        lut_percentages,
        f"{style['marker']}-",
        color=style["color"],
        linewidth=2,
        label=style["display_name"],
    )

    ax.set_xlabel("Queue Size")
    ax.set_ylabel("LUT Utilization (%)")
    ax.set_title(title or "LUT Utilization Percentage vs Queue Size")
    ax.set_xscale("log", base=2)
    ax.grid(True)

    # Add legend if plotting multiple architectures
    if arch_name:
        ax.legend(fontsize=12)


def plot_register_usage_vs_queue_size(ax, data_dict, title=None, arch_name=None):
    """
    Plot register usage vs queue size.

    Args:
        ax (matplotlib.axes.Axes): The axes to plot on
        data_dict (dict): Data from parsers.process_directory
        title (str, optional): Custom title for the plot
        arch_name (str, optional): Architecture name to determine plot style
    """
    queue_sizes, registers = dp.get_register_usage(data_dict)

    # Get architecture-specific style
    style = (
        get_arch_style(arch_name)
        if arch_name
        else {"color": "purple", "marker": "^", "display_name": "Architecture"}
    )

    ax.plot(
        queue_sizes,
        registers,
        f"{style['marker']}-",
        color=style["color"],
        linewidth=2,
        label=style["display_name"],
    )

    ax.set_xlabel("Queue Size")
    ax.set_ylabel("Register Usage (Count)")
    ax.set_title(title or "Register Usage vs Queue Size")
    ax.set_xscale("log", base=2)
    ax.grid(True)

    # Add legend if plotting multiple architectures
    if arch_name:
        ax.legend(fontsize=12)


def plot_register_utilization_vs_queue_size(ax, data_dict, title=None, arch_name=None):
    """
    Plot register utilization percentage vs queue size.

    Args:
        ax (matplotlib.axes.Axes): The axes to plot on
        data_dict (dict): Data from parsers.process_directory
        title (str, optional): Custom title for the plot
        arch_name (str, optional): Architecture name to determine plot style
    """
    queue_sizes, reg_percentages = dp.get_register_utilization(data_dict)

    # Get architecture-specific style
    style = (
        get_arch_style(arch_name)
        if arch_name
        else {"color": "orange", "marker": "*", "display_name": "Architecture"}
    )

    ax.plot(
        queue_sizes,
        reg_percentages,
        f"{style['marker']}-",
        color=style["color"],
        linewidth=2,
        label=style["display_name"],
    )

    ax.set_xlabel("Queue Size")
    ax.set_ylabel("Register Utilization (%)")
    ax.set_title(title or "Register Utilization Percentage vs Queue Size")
    ax.set_xscale("log", base=2)
    ax.grid(True)

    # Add legend if plotting multiple architectures
    if arch_name:
        ax.legend(fontsize=12)


def plot_bram_usage_vs_queue_size(ax, data_dict, title=None, arch_name=None):
    """
    Plot BRAM usage vs queue size.

    Args:
        ax (matplotlib.axes.Axes): The axes to plot on
        data_dict (dict): Data from parsers.process_directory
        title (str, optional): Custom title for the plot
        arch_name (str, optional): Architecture name to determine plot style
    """
    queue_sizes, brams = dp.get_bram_usage(data_dict)

    # Get architecture-specific style
    style = (
        get_arch_style(arch_name)
        if arch_name
        else {"color": "brown", "marker": "D", "display_name": "Architecture"}
    )

    ax.plot(
        queue_sizes,
        brams,
        f"{style['marker']}-",
        color=style["color"],
        linewidth=2,
        label=style["display_name"],
    )

    ax.set_xlabel("Queue Size")
    ax.set_ylabel("BRAM Usage (Count)")
    ax.set_title(title or "BRAM Usage vs Queue Size")
    ax.set_xscale("log", base=2)
    ax.grid(True)

    # Add legend if plotting multiple architectures
    if arch_name:
        ax.legend(fontsize=12)


def plot_bram_utilization_vs_queue_size(ax, data_dict, title=None, arch_name=None):
    """
    Plot BRAM utilization percentage vs queue size.

    Args:
        ax (matplotlib.axes.Axes): The axes to plot on
        data_dict (dict): Data from parsers.process_directory
        title (str, optional): Custom title for the plot
        arch_name (str, optional): Architecture name to determine plot style
    """
    # Check if data_dict is a dictionary before calling get_bram_utilization
    if not isinstance(data_dict, dict):
        return
    queue_sizes, bram_percentages = dp.get_bram_utilization(data_dict)

    # Get architecture-specific style
    style = (
        get_arch_style(arch_name)
        if arch_name
        else {"color": "magenta", "marker": "X", "display_name": "Architecture"}
    )

    ax.plot(
        queue_sizes,
        bram_percentages,
        f"{style['marker']}-",
        color=style["color"],
        linewidth=2,
        label=style["display_name"],
    )

    ax.set_xlabel("Queue Size")
    ax.set_ylabel("BRAM Utilization (%)")
    ax.set_title(title or "BRAM Utilization Percentage vs Queue Size")
    ax.set_xscale("log", base=2)
    ax.grid(True)

    # Add legend if plotting multiple architectures
    if arch_name:
        ax.legend(fontsize=12)


def plot_performance_comparison(ax, data_dict, arch_list, operation, title=None):
    """
    Plot performance comparison across different architectures for a specific operation.

    Args:
        ax (matplotlib.axes.Axes): The axes to plot on
        data_dict (dict): Dictionary of data dictionaries for each architecture
        arch_list (list): List of architecture names
        operation (str): Operation type ('enqueue', 'dequeue', 'replace')
        title (str, optional): Custom title for the plot
    """
    for arch_name in arch_list:
        if arch_name in data_dict:
            # Get architecture-specific style
            style = get_arch_style(arch_name)

            # Check if data_dict[arch_name] is a dictionary before calling compute_performance
            if isinstance(data_dict[arch_name], dict):
                queue_sizes, performance = dp.compute_performance(
                    data_dict[arch_name], arch_name, operation
                )
            else:
                continue
            ax.plot(
                queue_sizes,
                performance,
                f"{style['marker']}-",
                color=style["color"],
                label=style["display_name"],
                linewidth=2,
            )

    ax.set_xlabel("Queue Size")
    ax.set_ylabel("Performance (MHz * ops/cycle)")
    ax.set_title(title or f"{operation.capitalize()} Performance")
    ax.set_xscale("log", base=2)
    ax.grid(True)
    ax.legend(fontsize=12)


def plot_resource_comparison(ax, data_dict, arch_list, title=None):
    for arch_name in arch_list:
        if arch_name in data_dict:
            # Get architecture-specific style
            style = get_arch_style(arch_name)

            # Check if data_dict[arch_name] is a dictionary before calling compute_resource_utilization
            if isinstance(data_dict[arch_name], dict):
                queue_sizes, resource_utilization = dp.compute_resource_utilization(
                    data_dict[arch_name]
                )
            else:
                continue
            ax.plot(
                queue_sizes,
                resource_utilization,
                f"{style['marker']}-",
                color=style["color"],
                label=style["display_name"],
                linewidth=2,
            )

    ax.set_xlabel("Queue Size")
    ax.set_ylabel("Resource Utilization (%)")
    ax.set_title(title or "Resource Utilization Comparison")
    ax.set_xscale("log", base=2)
    ax.set_yscale("log")
    ax.grid(True)
    ax.legend(fontsize=12)


def plot_efficiency_comparison(ax, data_dict, arch_list, operation, title=None):
    """
    Plot resource utilization efficiency comparison across architectures.
    Lower values are better (less resources per performance unit).

    Args:
        ax (matplotlib.axes.Axes): The axes to plot on
        data_dict (dict): Dictionary of data dictionaries for each architecture
        arch_list (list): List of architecture names
        operation (str): Operation type ('enqueue', 'dequeue', 'replace')
        title (str, optional): Custom title for the plot
    """
    for arch_name in arch_list:
        if arch_name in data_dict:
            # Get architecture-specific style
            style = get_arch_style(arch_name)

            # Check if data_dict[arch_name] is a dictionary before calling compute_resource_utilization_efficiency
            if isinstance(data_dict[arch_name], dict):
                queue_sizes, efficiency = dp.compute_resource_utilization_efficiency(
                    data_dict[arch_name], arch_name, operation
                )
            else:
                continue

            ax.plot(
                queue_sizes,
                efficiency,
                f"{style['marker']}-",
                color=style["color"],
                label=style["display_name"],
                linewidth=2,
            )

    ax.set_xlabel("Queue Size")
    ax.set_ylabel("Performance / Resource")
    ax.set_title(title or f"{operation.capitalize()} Resource Efficiency")
    ax.set_xscale("log", base=2)
    ax.set_yscale("log")
    ax.grid(True)
    ax.legend(fontsize=12)


def create_summary_plots(data_dict, architecture, output_path=None, enqueue_option=None):
    """
    Create a summary of plots for a specific architecture.

    Args:
        data_dict (dict): Data from parsers.process_directory
        architecture (str): Name of the architecture being analyzed
        output_path (str, optional): Path to save the figure to
        enqueue_option (str, optional): "enabled", "disabled", or None for architectures without enqueue variants

    Returns:
        matplotlib.figure.Figure: The figure containing all subplots
    """
    # Create a 3x3 grid of subplots
    fig, axs = plt.subplots(3, 3, figsize=(18, 16))
    
    # Add enqueue state to the title if provided
    title = f"Performance Analysis for {architecture} Architecture"
    if enqueue_option:
        title += f" (Enqueue {enqueue_option.capitalize()})"
    fig.suptitle(title, fontsize=32)

    # Convert display name to architecture key for style lookup
    arch_key = architecture.lower().replace(" ", "_").split("(")[0].strip()
    
    # Append enqueue option to architecture key if provided
    if enqueue_option:
        arch_key += f"_enq_{enqueue_option}"

    # Row 1: Basic metrics
    plot_frequency_vs_queue_size(axs[0, 0], data_dict, arch_name=arch_key)
    plot_lut_usage_vs_queue_size(axs[0, 1], data_dict, arch_name=arch_key)
    plot_register_usage_vs_queue_size(axs[0, 2], data_dict, arch_name=arch_key)

    # Row 2: Utilization percentages and BRAM
    plot_lut_utilization_vs_queue_size(axs[1, 0], data_dict, arch_name=arch_key)
    plot_register_utilization_vs_queue_size(axs[1, 1], data_dict, arch_name=arch_key)
    plot_bram_usage_vs_queue_size(axs[1, 2], data_dict, arch_name=arch_key)

    # Row 3: Performance for different operations
    operations = ["enqueue", "dequeue", "replace"]
    for idx, operation in enumerate(operations):
        # Skip enqueue plot if enqueue is disabled
        if operation == "enqueue" and enqueue_option == "disabled":
            axs[2, idx].set_visible(False)
            continue
            
        # Create dummy comparison with just this architecture
        arch_list = [arch_key]
        dummy_dict = {arch_key: data_dict}
        plot_performance_comparison(axs[2, idx], dummy_dict, arch_list, operation)

    # Adjust layout
    plt.tight_layout(rect=(0, 0, 1, 0.97))  # Leave space for suptitle

    # Save if output path provided
    if output_path:
        os.makedirs(os.path.dirname(output_path), exist_ok=True)
        plt.savefig(output_path, dpi=300, bbox_inches="tight")
        print(f"Saved summary plots to {output_path}")

    return fig


def create_architecture_variant_comparison(variant_data_dict, base_architecture, output_path=None):
    """
    Create a comparison plot for different variants of the same architecture (e.g., RegisterArray with
    different options like cycled, enqueue enabled/disabled).

    Args:
        variant_data_dict (dict): Dictionary mapping variant names to their data dictionaries
        base_architecture (str): Base name of the architecture (e.g., "RegisterArray")
        output_path (str, optional): Path to save the figure to

    Returns:
        matplotlib.figure.Figure: The figure containing the comparison plots
    """
    # Create a 5x3 grid to match the style of create_comparison_plots
    fig, axs = plt.subplots(5, 3, figsize=(32, 40))
    # fig.suptitle(f"{base_architecture} Variants Comparison", fontsize=32, y=0.97)
    
    # Row 1: Maximum achieved frequency comparison
    for variant, data in variant_data_dict.items():
        style = get_arch_style(variant)
        queue_sizes, frequencies = dp.get_max_achieved_frequency(data)
        axs[0, 0].plot(
            queue_sizes,
            frequencies,
            f"{style['marker']}-",
            color=style["color"],
            label=style["display_name"],
            linewidth=2,
        )
    axs[0, 0].set_xlabel("Queue Size")
    axs[0, 0].set_ylabel("Maximum Frequency (MHz)")
    axs[0, 0].set_title("Maximum Achieved Frequency")
    axs[0, 0].set_xscale("log", base=2)
    axs[0, 0].grid(True)
    axs[0, 0].legend(fontsize=12)
    
    # Hide the other plots in first row
    axs[0, 1].set_visible(False)
    axs[0, 2].set_visible(False)
    
    # Row 2: Resource utilization comparisons
    # Plot LUT utilization comparison
    for variant, data in variant_data_dict.items():
        style = get_arch_style(variant)
        queue_sizes, lut_percentages = dp.get_lut_utilization(data)
        axs[1, 0].plot(
            queue_sizes,
            lut_percentages,
            f"{style['marker']}-",
            color=style["color"],
            label=style["display_name"],
            linewidth=2,
        )
    axs[1, 0].set_xlabel("Queue Size")
    axs[1, 0].set_ylabel("LUT Utilization (%)")
    axs[1, 0].set_title("LUT Utilization Comparison")
    axs[1, 0].set_xscale("log", base=2)
    axs[1, 0].set_yscale("log")
    axs[1, 0].grid(True)
    axs[1, 0].legend(fontsize=12)
    
    # Plot Register utilization comparison
    for variant, data in variant_data_dict.items():
        style = get_arch_style(variant)
        queue_sizes, reg_percentages = dp.get_register_utilization(data)
        axs[1, 1].plot(
            queue_sizes,
            reg_percentages,
            f"{style['marker']}-",
            color=style["color"],
            label=style["display_name"],
            linewidth=2,
        )
    axs[1, 1].set_xlabel("Queue Size")
    axs[1, 1].set_ylabel("Register Utilization (%)")
    axs[1, 1].set_title("Register Utilization Comparison")
    axs[1, 1].set_xscale("log", base=2)
    axs[1, 1].set_yscale("log")
    axs[1, 1].grid(True)
    axs[1, 1].legend(fontsize=12)
    
    # Plot BRAM utilization comparison
    any_bram_usage = False
    for variant, data in variant_data_dict.items():
        style = get_arch_style(variant)
        queue_sizes, bram_percentages = dp.get_bram_utilization(data)
        if any(bram_percentages):  # Only plot if there's actual BRAM usage
            any_bram_usage = True
            axs[1, 2].plot(
                queue_sizes,
                bram_percentages,
                f"{style['marker']}-",
                color=style["color"],
                label=style["display_name"],
                linewidth=2,
            )
    
    if any_bram_usage:
        axs[1, 2].set_xlabel("Queue Size")
        axs[1, 2].set_ylabel("BRAM Utilization (%)")
        axs[1, 2].set_title("BRAM Utilization Comparison")
        axs[1, 2].set_xscale("log", base=2)
        axs[1, 2].set_yscale("log")
        axs[1, 2].grid(True)
        axs[1, 2].legend(fontsize=12)
    else:
        axs[1, 2].set_visible(False)
    
    # Row 3: Performance Comparisons
    # Plot Enqueue Performance
    enqueue_variants = {k: v for k, v in variant_data_dict.items() if "enq_enabled" in k or "enq_disabled" not in k}
    if enqueue_variants:
        for variant, data in enqueue_variants.items():
            style = get_arch_style(variant)
            queue_sizes, performance = dp.compute_performance(data, variant, "enqueue")
            axs[2, 0].plot(
                queue_sizes,
                performance,
                f"{style['marker']}-",
                color=style["color"],
                label=style["display_name"],
                linewidth=2,
            )
        axs[2, 0].set_xlabel("Queue Size")
        axs[2, 0].set_ylabel("Performance (MHz * ops/cycle)")
        axs[2, 0].set_title("Enqueue Performance")
        axs[2, 0].set_xscale("log", base=2)
        axs[2, 0].grid(True)
        axs[2, 0].legend(fontsize=12)
    else:
        axs[2, 0].set_visible(False)
    
    # Plot Dequeue and Replace Performance in one plot
    for variant, data in variant_data_dict.items():
        style = get_arch_style(variant)
        queue_sizes, performance = dp.compute_performance(data, variant, "dequeue")
        axs[2, 1].plot(
            queue_sizes,
            performance,
            f"{style['marker']}-",
            color=style["color"],
            label=style["display_name"],
            linewidth=2,
        )
    axs[2, 1].set_xlabel("Queue Size")
    axs[2, 1].set_ylabel("Performance (MHz * ops/cycle)")
    axs[2, 1].set_title("Dequeue and Replace Performance")
    axs[2, 1].set_xscale("log", base=2)
    axs[2, 1].grid(True)
    axs[2, 1].legend(fontsize=12)
    
    # Hide the third plot in third row
    axs[2, 2].set_visible(False)
    
    # Row 4: Resource Efficiency Comparisons
    # Plot Enqueue Efficiency
    if enqueue_variants:
        for variant, data in enqueue_variants.items():
            style = get_arch_style(variant)
            queue_sizes, efficiency = dp.compute_resource_utilization_efficiency(data, variant, "enqueue")
            axs[3, 0].plot(
                queue_sizes,
                efficiency,
                f"{style['marker']}-",
                color=style["color"],
                label=style["display_name"],
                linewidth=2,
            )
        axs[3, 0].set_xlabel("Queue Size")
        axs[3, 0].set_ylabel("Performance / Resource")
        axs[3, 0].set_title("Enqueue Resource Efficiency")
        axs[3, 0].set_xscale("log", base=2)
        axs[3, 0].set_yscale("log")
        axs[3, 0].grid(True)
        axs[3, 0].legend(fontsize=12)
    else:
        axs[3, 0].set_visible(False)
    
    # Plot Dequeue and Replace Efficiency
    for variant, data in variant_data_dict.items():
        style = get_arch_style(variant)
        queue_sizes, efficiency = dp.compute_resource_utilization_efficiency(data, variant, "dequeue")
        axs[3, 1].plot(
            queue_sizes,
            efficiency,
            f"{style['marker']}-",
            color=style["color"],
            label=style["display_name"],
            linewidth=2,
        )
    axs[3, 1].set_xlabel("Queue Size")
    axs[3, 1].set_ylabel("Performance / Resource")
    axs[3, 1].set_title("Dequeue and Replace Efficiency")
    axs[3, 1].set_xscale("log", base=2)
    axs[3, 1].set_yscale("log")
    axs[3, 1].grid(True)
    axs[3, 1].legend(fontsize=12)
    
    # Hide the third plot in fourth row
    axs[3, 2].set_visible(False)
    
    # Row 5: Resource Utilization Comparison
    plot_resource_comparison(axs[4, 0], variant_data_dict, list(variant_data_dict.keys()))
    
    # Hide the other plots in fifth row
    axs[4, 1].set_visible(False)
    axs[4, 2].set_visible(False)
    
    # Adjust layout
    plt.tight_layout(rect=(0, 0, 1, 0.97))  # Leave space for suptitle
    
    # Save if output path provided
    if output_path:
        os.makedirs(os.path.dirname(output_path), exist_ok=True)
        plt.savefig(output_path, dpi=300, bbox_inches="tight")
        print(f"Saved {base_architecture} variant comparison to {output_path}")
    
    return fig


def create_comparison_plots(data_dict_dict, output_path=None):
    """
    Create a comparison of all architectures.

    Args:
        data_dict_dict (dict): Dictionary mapping architecture names to their data dictionaries
        output_path (str, optional): Path to save the figure to

    Returns:
        matplotlib.figure.Figure: The figure containing all comparison plots
    """
    # Get available architecture names from the data
    arch_list = list(data_dict_dict.keys())

    # Create a 3x3 grid for comparison plots
    fig, axs = plt.subplots(5, 3, figsize=(32, 40))
    fig.suptitle(
        "Hardware Queue Architecture Comparison", fontsize=32, y=0.97
    )  # Adjusted y position

    # Row 1: Maximum achieved frequency comparison
    # Plot 1: Maximum achieved frequency comparison
    for arch_name, data_dict in data_dict_dict.items():
        style = get_arch_style(arch_name)
        # Check if data_dict is a dictionary before calling get_max_achieved_frequency
        if isinstance(data_dict, dict):
            queue_sizes, frequencies = dp.get_max_achieved_frequency(data_dict)
            axs[0, 0].plot(
                queue_sizes,
                frequencies,
                f"{style['marker']}-",
                color=style["color"],
                label=style["display_name"],
                linewidth=2,
            )
    axs[0, 0].set_xlabel("Queue Size")
    axs[0, 0].set_ylabel("Maximum Frequency (MHz)")
    axs[0, 0].set_title("Maximum Achieved Frequency")
    axs[0, 0].set_xscale("log", base=2)
    axs[0, 0].grid(True)
    axs[0, 0].legend(fontsize=12)

    axs[0, 1].set_visible(False)  # Empty plot for layout balance
    axs[0, 2].set_visible(False)  # Empty plot for layout balance

    # Row 2: Resource utilization comparisons
    # Plot 2: LUT utilization comparison
    for arch_name, data_dict in data_dict_dict.items():
        style = get_arch_style(arch_name)
        # Check if data_dict is a dictionary before calling get_lut_utilization
        if isinstance(data_dict, dict):
            queue_sizes, lut_percentages = dp.get_lut_utilization(data_dict)
            axs[1, 0].plot(
                queue_sizes,
                lut_percentages,
                f"{style['marker']}-",
                color=style["color"],
                label=style["display_name"],
                linewidth=2,
            )
    axs[1, 0].set_xlabel("Queue Size")
    axs[1, 0].set_ylabel("LUT Utilization (%)")
    axs[1, 0].set_title("LUT Utilization Comparison")
    axs[1, 0].set_xscale("log", base=2)
    axs[1, 0].set_yscale("log")
    axs[1, 0].grid(True)
    axs[1, 0].legend(fontsize=12)

    # Plot 3: Register utilization comparison
    for arch_name, data_dict in data_dict_dict.items():
        style = get_arch_style(arch_name)
        # Check if data_dict is a dictionary before calling get_register_utilization
        if isinstance(data_dict, dict):
            queue_sizes, reg_percentages = dp.get_register_utilization(data_dict)
            axs[1, 1].plot(
                queue_sizes,
                reg_percentages,
                f"{style['marker']}-",
                color=style["color"],
                label=style["display_name"],
                linewidth=2,
            )
    axs[1, 1].set_xlabel("Queue Size")
    axs[1, 1].set_ylabel("Register Utilization (%)")
    axs[1, 1].set_title("Register Utilization Comparison")
    axs[1, 1].set_xscale("log", base=2)
    axs[1, 1].set_yscale("log")
    axs[1, 1].grid(True)
    axs[1, 1].legend(fontsize=12)

    # Plot 4: BRAM utilization comparison
    for arch_name, data_dict in data_dict_dict.items():
        style = get_arch_style(arch_name)
        # Check if data_dict is a dictionary before calling get_bram_utilization
        if isinstance(data_dict, dict):
            queue_sizes, bram_percentages = dp.get_bram_utilization(data_dict)
            if any(bram_percentages):  # Only plot if there's actual BRAM usage
                axs[1, 2].plot(
                    queue_sizes,
                    bram_percentages,
                    f"{style['marker']}-",
                    color=style["color"],
                    label=style["display_name"],
                    linewidth=2,
                )
    axs[1, 2].set_xlabel("Queue Size")
    axs[1, 2].set_ylabel("BRAM Utilization (%)")
    axs[1, 2].set_title("BRAM Utilization Comparison")
    axs[1, 2].set_xscale("log", base=2)
    axs[1, 2].set_yscale("log")
    axs[1, 2].grid(True)
    axs[1, 2].legend(fontsize=12)

    # Row 2 and 3: Performance and efficiency comparisons
    operations = ["enqueue", "dequeue", "replace"]

    # Performance comparisons for different operations
    # Create filtered arch_list for enqueue operation 
    # Exclude BRAM trees and hybrid trees which don't support enqueue
    # Also exclude architectures with enqueue disabled
    enqueue_arch_list = [
        arch for arch in arch_list 
        if "bram_tree" not in arch.lower() 
        and "hybrid_tree" not in arch.lower()
        and "enq_disabled" not in arch.lower()
    ]
    enqueue_data_dict = {
        arch: data
        for arch, data in data_dict_dict.items()
        if "bram_tree" not in arch.lower() 
        and "hybrid_tree" not in arch.lower()
        and "enq_disabled" not in arch.lower() 
    }

    # Use filtered lists for enqueue operations
    plot_performance_comparison(
        axs[2, 0], enqueue_data_dict, enqueue_arch_list, operations[0]
    )  # Enqueue performance
    
    # Combined Dequeue and Replace Performance plot
    plot_performance_comparison(
        axs[2, 1], data_dict_dict, arch_list, operations[2], title="Dequeue and Replace Performance"
    )  # Combined Dequeue and Replace performance
    
    # Empty plot for layout balance
    axs[2, 2].set_visible(False)

    # Resource efficiency comparisons for different operations
    plot_efficiency_comparison(
        axs[3, 0], enqueue_data_dict, enqueue_arch_list, operations[0]
    )  # Enqueue efficiency
    
    # Combined Dequeue and Replace Efficiency plot
    plot_efficiency_comparison(
        axs[3, 1], data_dict_dict, arch_list, operations[2], title="Dequeue and Replace Efficiency"
    )  # Combined Dequeue and Replace efficiency
    
    # Empty plot for layout balance
    axs[3, 2].set_visible(False)

    # Row 4: Resource utilization comparisons
    plot_resource_comparison(axs[4, 0], data_dict_dict, arch_list)

    axs[4, 1].set_visible(False)  # Empty plot for layout balance
    axs[4, 2].set_visible(False)  # Empty plot for layout balance

    # Adjust layout
    plt.tight_layout(rect=(0, 0, 1, 0.97))  # Modified to a more moderate top margin

    # Save if output path provided
    if output_path:
        os.makedirs(os.path.dirname(output_path), exist_ok=True)
        plt.savefig(output_path, dpi=300, bbox_inches="tight")
        print(f"Saved comparison plots to {output_path}")

    return fig


def create_multi_arch_plot(
    plot_function, data_dict_dict, operation=None, title=None, output_path=None
):
    """
    Create a plot comparing a specific metric across multiple architectures.

    Args:
        plot_function (function): The plotting function to use
        data_dict_dict (dict): Dictionary mapping architecture names to their data dictionaries
        operation (str, optional): Operation type for performance/efficiency plots
        title (str, optional): Custom title for the plot
        output_path (str, optional): Path to save the figure to

    Returns:
        matplotlib.figure.Figure: The figure containing the plot
    """
    # Create figure and axes
    fig, ax = plt.subplots(figsize=(12, 8))

    # Plot each architecture
    for arch_name, data_dict in data_dict_dict.items():
        if operation:
            # Function requires operation parameter
            plot_function(
                ax, data_dict, title=title, arch_name=arch_name, operation=operation
            )
        else:
            # Regular metric plot
            plot_function(ax, data_dict, title=title, arch_name=arch_name)

    # Save if output path provided
    if output_path:
        os.makedirs(os.path.dirname(output_path), exist_ok=True)
        plt.savefig(output_path, dpi=300, bbox_inches="tight")
        print(f"Saved plot to {output_path}")

    return fig


def process_and_plot_all(base_dir, output_dir=None):
    """
    Process all directories and create plots for each architecture.

    Args:
        base_dir (str): Base directory containing subdirectories for each architecture
        output_dir (str, optional): Directory to save plots to
    """
    # Create output directory if not provided
    if not output_dir:
        output_dir = os.path.join(base_dir, "plots")

    # Setup plot style
    setup_plot_style()

    # Dictionary to collect data for comparison plots
    all_data = {}

    # Process each architecture directory
    for arch_dir in os.listdir(base_dir):
        arch_path = os.path.join(base_dir, arch_dir)

        # Skip if not a directory or doesn't contain vivado_analysis_results
        if not os.path.isdir(arch_path):
            continue

        results_dirs = [
            d for d in os.listdir(arch_path) if "vivado_analysis_results" in d
        ]

        if not results_dirs:
            continue

        # Process each results directory
        for results_dir in results_dirs:
            log_dir = os.path.join(arch_path, results_dir)

            # Skip if not a directory
            if not os.path.isdir(log_dir):
                continue

            # Process data
            result = parsers.process_directory(log_dir)

            # Handle special case for architectures with enqueue variants
            if isinstance(result, tuple) and len(result) == 2:
                enq_disabled_data, enq_enabled_data = result
                
                # Skip if no data
                if not enq_disabled_data or not enq_enabled_data:
                    print(f"No data found in {log_dir}")
                    continue
                
                # Store both variants with different keys
                if arch_dir == "RegisterArray":
                    if "cycled" in results_dir.lower():
                        all_data["register_array_cycled_enq_disabled"] = enq_disabled_data
                        all_data["register_array_cycled_enq_enabled"] = enq_enabled_data
                    else:
                        all_data["register_array_enq_disabled"] = enq_disabled_data
                        all_data["register_array_enq_enabled"] = enq_enabled_data
                elif arch_dir == "RegisterTree":
                    all_data["register_tree_enq_disabled"] = enq_disabled_data
                    all_data["register_tree_enq_enabled"] = enq_enabled_data
                else:
                    # Generic handling for other architectures with enqueue variants
                    all_data[f"{arch_dir.lower()}_enq_disabled"] = enq_disabled_data
                    all_data[f"{arch_dir.lower()}_enq_enabled"] = enq_enabled_data
            else:
                # Regular case for other architectures
                data_dict = result

                # Skip if no data
                if not data_dict:
                    print(f"No data found in {log_dir}")
                    continue

                # Store data for comparison
                all_data[arch_dir] = data_dict

    # Create comparison plots if we have data for multiple architectures
    if len(all_data) > 1:
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        comparison_path = os.path.join(output_dir, f"architecture_comparison_{timestamp}.png")
        create_comparison_plots(all_data, comparison_path)
        
        # Create variant comparisons for architectures with multiple variants
        # Handle RegisterArray variants
        reg_array_variants = {k: v for k, v in all_data.items() if "register_array" in k.lower()}
        if len(reg_array_variants) > 1:
            reg_array_path = os.path.join(output_dir, f"register_array_comparison_{timestamp}.png")
            create_architecture_variant_comparison(reg_array_variants, "RegisterArray", reg_array_path)
        
        # Handle RegisterTree variants
        reg_tree_variants = {k: v for k, v in all_data.items() if "register_tree" in k.lower()}
        if len(reg_tree_variants) > 1:
            reg_tree_path = os.path.join(output_dir, f"register_tree_comparison_{timestamp}.png")
            create_architecture_variant_comparison(reg_tree_variants, "RegisterTree", reg_tree_path)


if __name__ == "__main__":
    # NOTE - Input base_dir as an absolute path or run this script under hwpq_qw2246 directory
    base_dir = "./"
    output_dir = os.path.join(base_dir, OUTPUT_DIR)
    process_and_plot_all(base_dir, output_dir)
