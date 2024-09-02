/*
    this is an implementation of the register-array verilog pseudocode proposed by Huang 2014
    Paper
*/
module register_array #(
    parameter QUEUE_SIZE = 4, 
    parameter DATA_WIDTH = 32
)
(
    input  logic          clk,
    input  logic          replace,
    input  logic [DATA_WIDTH-1:0]   new_entry,
    output logic [DATA_WIDTH-1:0]   max_entry
);

    logic [DATA_WIDTH-1:0] register [QUEUE_SIZE-1:0];

    logic [DATA_WIDTH-1:0] tmp_register [QUEUE_SIZE-2:0];

    logic [DATA_WIDTH-1:0] max [QUEUE_SIZE/2-1:0];
    logic [DATA_WIDTH-1:0] min [QUEUE_SIZE/2-1:0];

    // synthesis translate_off
    initial begin
        for (int i = 0; i < QUEUE_SIZE; i++) begin
            register[i] = $urandom_range(0, 100);
        end
    end
    // synthesis translate_on

    always_comb begin
        for (int i = 0; i < QUEUE_SIZE; i++) begin
            tmp_register[i] = register[i];
        end

        if (replace) begin
            tmp_register[0] = new_entry;
        end

        max[0] = (tmp_register[0] > register[1]) ? tmp_register[0] : register[1];
        min[0] = (tmp_register[0] < register[1]) ? tmp_register[0] : register[1];

        for (int i = 1; i <= QUEUE_SIZE/2-1; i++) begin
            max[i] = (register[2*i] > register[2*i+1]) ? register[2*i] : register[2*i+1];
            min[i] = (register[2*i] < register[2*i+1]) ? register[2*i] : register[2*i+1];
        end

        for (int i = 1; i <= QUEUE_SIZE/2-1; i++) begin
            tmp_register[2*i-1] = (min[i-1] > max[i]) ? min[i-1] : max[i];
            tmp_register[2*i] = (min[i-1] < max[i]) ? min[i-1] : max[i];
        end

        max_entry = register[0];
    end

    always_ff @(posedge clk) begin
        register[0] <= max[0];
        for (int i = 1; i <= QUEUE_SIZE-1; i++) begin
            register[i] <= tmp_register[i];
        end
        register[QUEUE_SIZE-1] <= min[QUEUE_SIZE/2-1];       
    end

endmodule
