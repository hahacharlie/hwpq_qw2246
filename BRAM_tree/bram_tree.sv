/*******************************************************************************
  Module Name: bram_tree
  Description: Implements a tree-like structure using BRAM for storage. It 
               maintains a sorted order by comparing and swapping entries, with 
               the highest value always at the root.
  Inputs:  clk       - Clock signal
           new_entry - New data to be inserted into the tree (WIDTH bits)
  Outputs: top_entry - The highest value in the tree (WIDTH bits)
*******************************************************************************/

module bram_tree #(parameter WIDTH = 32, DEPTH = 1024) (
    input  logic                clk,
    input  logic [WIDTH-1:0]    new_entry,
    output logic [WIDTH-1:0]    top_entry
);
    // BRAM-based storage for the tree structure
    logic [WIDTH-1:0] bram [0:DEPTH-1];
    
    // Index to keep track of the current position in the BRAM
    logic [$clog2(DEPTH)-1:0] index;

    always_ff @(posedge clk) begin
        // Compare the new entry with the current entry at 'index', if new_entry is greater, replace the current entry
        if (new_entry > bram[index]) begin
            bram[index] <= new_entry;
        end
        
        // Move to the next index, wrapping around when reaching DEPTH
        index <= (index + 1) % DEPTH;
    end

    // The root of the tree (highest value) is always at index 0
    assign top_entry = bram[0];
endmodule
