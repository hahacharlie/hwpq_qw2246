/*
    this is an implementation of the register-array verilog pseudocode proposed by Huang 2014
    Paper
*/

module register_array #(
    parameter QUEUE_SIZE = 4,  // Define the size of the queue
    parameter DATA_WIDTH = 32   // Define the width of the data
) (
    input  logic                  clk,        // Clock signal
    input  logic                  rst,        // Reset signal
    input  logic                  replace,    // Signal to indicate replacement
    input  logic [DATA_WIDTH-1:0] new_entry,  // New entry to be inserted
    output logic [DATA_WIDTH-1:0] max_entry   // Output the maximum entry
);

  localparam pair_count = (QUEUE_SIZE + 1) / 2;  // Calculate the number of pairs

  logic [DATA_WIDTH-1:0] register[0:QUEUE_SIZE-1];  // Array to hold the register values

  logic [DATA_WIDTH-1:0] tmp_register[0:QUEUE_SIZE-1];  // Temporary register array

  logic [DATA_WIDTH-1:0] max[0:((QUEUE_SIZE + 1)/2)-1];  // Adjusted size for max array
  logic [DATA_WIDTH-1:0] min[0:((QUEUE_SIZE + 1)/2)-1];  // Adjusted size for min array

  always_ff @(posedge clk) begin
    if (rst) begin
      for (int j = 0; j < QUEUE_SIZE; j++) begin
        register[j] <= (j + 1) * 10;  // Initialize tree entries to some values
      end
    end else begin
      for (int i = 0; i < QUEUE_SIZE; i++) begin
        register[i] <= tmp_register[i];  // Update the register with temporary register values
      end
      if (replace) begin
        register[0] <= new_entry;
      end
    end
  end

  always_comb begin
    // Copy register values to temporary register
    for (int i = 0; i < QUEUE_SIZE; i++) begin
      tmp_register[i] = register[i];
    end

    // Calculate max and min for pairs
    for (int i = 0; i < pair_count; i++) begin
      if ((2 * i + 1) < QUEUE_SIZE) begin
        max[i] = (register[2*i] > register[2*i+1]) ? register[2*i] : register[2*i+1];
        min[i] = (register[2*i] < register[2*i+1]) ? register[2*i] : register[2*i+1];
      end else begin
        max[i] = register[2*i];  // Only one element left
        min[i] = register[2*i];  // Only one element left
      end
    end

    // Update temporary register with min/max
    for (int i = 1; i < pair_count; i++) begin
      tmp_register[2*i-1] = (min[i-1] > max[i]) ? min[i-1] : max[i];
      tmp_register[2*i]   = (min[i-1] < max[i]) ? min[i-1] : max[i];
    end

    tmp_register[0] = max[0];

  end

  assign max_entry = register[0];

endmodule
