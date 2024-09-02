module register_array #(
    parameter QUEUE_SIZE = 4,
    parameter WIDTH = 32
) (
    input  logic                clk,
    input  logic [WIDTH-1:0]    new_entry,
    output logic [WIDTH-1:0]    top_entry
);
    // Define a register array of QUEUE_SIZE elements, each WIDTH bits wide
    logic [WIDTH-1:0] reg_array [0:QUEUE_SIZE-1];
    
    // Temporary registers for intermediate comparisons
    logic [WIDTH-1:0] tmp_reg0, tmp_reg1;

    always_ff @(posedge clk) begin
        // Replace the leftmost node with the new entry
        reg_array[0] <= new_entry;
        
        // Pulsate the array twice
        for (int i = 0; i < 2; i++) begin
            // Swap even entries with odd entries
            for (int j = 0; j < QUEUE_SIZE/2; j++) begin
                tmp_reg0 = reg_array[2*j];
                tmp_reg1 = reg_array[2*j+1];
                reg_array[2*j] <= (tmp_reg0 > tmp_reg1) ? tmp_reg0 : tmp_reg1;
                reg_array[2*j+1] <= (tmp_reg0 > tmp_reg1) ? tmp_reg1 : tmp_reg0;
            end
            
            // Swap odd entries with even entries
            for (int j = 0; j < QUEUE_SIZE/2-1; j++) begin
                tmp_reg0 = reg_array[2*j+1];
                tmp_reg1 = reg_array[2*j+2];
                reg_array[2*j+1] <= (tmp_reg0 > tmp_reg1) ? tmp_reg0 : tmp_reg1;
                reg_array[2*j+2] <= (tmp_reg0 > tmp_reg1) ? tmp_reg1 : tmp_reg0;
            end
        end

        // Output the highest value
        top_entry <= reg_array[0];
    end
endmodule
