`timescale 1ns / 1ps

module systolic_array_proc_tb;

  // Parameters
  localparam DATA_WIDTH = 32;

  // Inputs
  logic clk;
  logic rst;
  logic en;
  logic [DATA_WIDTH-1:0] b_previous_i;
  logic [DATA_WIDTH-1:0] b_i;
  logic [DATA_WIDTH-1:0] a_previous_i;
  logic [DATA_WIDTH-1:0] a_i;

  // Outputs
  logic [DATA_WIDTH-1:0] b_previous_o;
  logic [DATA_WIDTH-1:0] b_o;
  logic [DATA_WIDTH-1:0] a_previous_o;
  logic [DATA_WIDTH-1:0] a_o;

  // Instantiate the Unit Under Test (UUT)
  systolic_array_proc #(
    .DATA_WIDTH(DATA_WIDTH)
  ) uut (
    .clk(clk),
    .rst(rst),
    .en(en),
    .b_previous_i(b_previous_i),
    .b_i(b_i),
    .a_previous_i(a_previous_i),
    .a_i(a_i),
    .b_previous_o(b_previous_o),
    .b_o(b_o),
    .a_previous_o(a_previous_o),
    .a_o(a_o)
  );

  // Clock generation
  initial begin
    clk = 0;
    forever #5 clk = ~clk; // 100MHz clock
  end

  // Test sequence
  initial begin
    // Initialize Inputs
    rst = 1;
    en = 0;
    b_previous_i = 0;
    b_i = 0;
    a_previous_i = 0;
    a_i = 0;

    // Wait for global reset
    #10;
    rst = 0;

    // Test case 1: Enable the module and provide inputs
    #10;
    en = 1;
    b_previous_i = 32'h00000001;
    b_i = 32'h00000002;
    a_previous_i = 32'h00000003;
    a_i = 32'h00000004;

    // Wait for a few clock cycles
    #20;

    // Test case 2: Change inputs
    b_previous_i = 32'h00000005;
    b_i = 32'h00000006;
    a_previous_i = 32'h00000007;
    a_i = 32'h00000008;

    // Wait for a few clock cycles
    #20;

    // Test case 3: Disable the module
    en = 0;

    // Wait for a few clock cycles
    #20;

    // Test case 4: Reset the module
    rst = 1;
    #10;
    rst = 0;

    // Wait for a few clock cycles
    #20;

    // Finish simulation
    $finish;
  end

endmodule
