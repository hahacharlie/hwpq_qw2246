/*
    this is an implementation of the register-array verilog pseudocode proposed by Huang 2014
    Paper
*/
module register_array #(
    parameter QUEUE_SIZE = 4, // Define the size of the queue
    parameter DATA_WIDTH = 32    // Define the width of the data
)
(
    input  logic          clk,                      // Clock signal
    input  logic          replace,                  // Signal to indicate replacement
    input  logic [DATA_WIDTH-1:0]   new_entry,      // New entry to be inserted
    output logic [DATA_WIDTH-1:0]   max_entry       // Output the maximum entry
);

    logic [DATA_WIDTH-1:0] register [QUEUE_SIZE-1:0]; // Array to hold the register values

    logic [DATA_WIDTH-1:0] tmp_register [QUEUE_SIZE-2:0]; // Temporary register array

    logic [DATA_WIDTH-1:0] max [QUEUE_SIZE/2-1:0]; // Array to hold max values
    logic [DATA_WIDTH-1:0] min [QUEUE_SIZE/2-1:0]; // Array to hold min values

    // synthesis off
    initial begin
        for (int i = 0; i < QUEUE_SIZE; i++) begin
            register[i] = $urandom_range(0, 100); // Initialize register with random values
        end
    end
    // synthesis on

    always_comb begin
        for (int i = 0; i < QUEUE_SIZE; i++) begin
            tmp_register[i] = register[i]; // Copy register values to temporary register
        end

        if (replace) begin
            tmp_register[0] = new_entry; // Replace the first entry if replace signal is high
        end

        max[0] = (tmp_register[0] > register[1]) ? tmp_register[0] : register[1]; // Calculate initial max
        min[0] = (tmp_register[0] < register[1]) ? tmp_register[0] : register[1]; // Calculate initial min

        for (int i = 1; i <= QUEUE_SIZE/2-1; i++) begin
            max[i] = (register[2*i] > register[2*i+1]) ? register[2*i] : register[2*i+1]; // Calculate max for pairs
            min[i] = (register[2*i] < register[2*i+1]) ? register[2*i] : register[2*i+1]; // Calculate min for pairs
        end

        for (int i = 1; i <= QUEUE_SIZE/2-1; i++) begin
            tmp_register[2*i-1] = (min[i-1] > max[i]) ? min[i-1] : max[i]; // Update temporary register with min/max
            tmp_register[2*i] = (min[i-1] < max[i]) ? min[i-1] : max[i];   // Update temporary register with min/max
        end

        max_entry = register[0]; // Assign the first register value to max_entry
    end

    always_ff @(posedge clk) begin
        register[0] <= max[0]; // Update the first register with max value
        for (int i = 1; i <= QUEUE_SIZE-1; i++) begin
            register[i] <= tmp_register[i]; // Update the register with temporary register values
        end
        register[QUEUE_SIZE-1] <= min[QUEUE_SIZE/2-1]; // Update the last register with min value
    end

endmodule






