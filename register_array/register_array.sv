/*******************************************************************************
  Module Name: register_array
  Description: A parameterized register array that maintains a sorted order of 
               entries. It compares and updates values on each clock cycle to 
               keep the highest value at the top.
  Inputs:  clk       - Clock signal
           new_entry - New value to be considered for insertion
  Outputs: top_entry - The highest value in the register array
*******************************************************************************/

module register_array #(parameter N = 4, WIDTH = 32) (
    input  logic                clk,
    input  logic [WIDTH-1:0]    new_entry,
    output logic [WIDTH-1:0]    top_entry
);
    // Define a register array of N elements, each WIDTH bits wide
    logic [WIDTH-1:0] reg_array [0:N-1];
    
    // Temporary registers for intermediate comparisons
    logic [WIDTH-1:0] tmp_reg0, tmp_reg1, tmp_reg2, tmp_reg3;

    always_ff @(posedge clk) begin
        // Compare new_entry with the second highest value
        tmp_reg0 = (new_entry > reg_array[1]) ? new_entry : reg_array[1];
        
        // Compare the current highest value with the third highest value
        tmp_reg1 = (reg_array[0] > reg_array[2]) ? reg_array[0] : reg_array[2];
        
        // Compare the result of previous comparison with the lowest value
        tmp_reg2 = (tmp_reg1 > reg_array[3]) ? tmp_reg1 : reg_array[3];

        // Update the register array with new values
        reg_array[0] <= tmp_reg0; // Highest value
        reg_array[1] <= tmp_reg1; // Second highest value
        reg_array[2] <= tmp_reg2; // Third highest value
        
        // Compare and store the lower of tmp_reg1 and tmp_reg2 in the last position
        reg_array[3] <= (tmp_reg1 > tmp_reg2) ? tmp_reg2 : tmp_reg1;

        // Output the highest value
        top_entry <= reg_array[0];
    end
endmodule
