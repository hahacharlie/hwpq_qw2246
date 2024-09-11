`timescale 1ns / 1ps

module systolic_array_proc0_tb;

  // Parameters
  localparam QUEUE_SIZE = 4;
  localparam DATA_WIDTH = 32;

  // Inputs
  logic clk;
  logic rst;
  logic insert;
  logic extract;
  logic [DATA_WIDTH-1:0] idata;

  // Outputs
  logic even;
  logic odd;
  logic [DATA_WIDTH-1:0] bo;
  logic [DATA_WIDTH-1:0] ao;

  // Instantiate the Unit Under Test (UUT)
  systolic_array_proc0 #(
    .QUEUE_SIZE(QUEUE_SIZE),
    .DATA_WIDTH(DATA_WIDTH)
  ) uut (
    .clk(clk),
    .rst(rst),
    .insert(insert),
    .extract(extract),
    .idata(idata),
    .even(even),
    .odd(odd),
    .bo(bo),
    .ao(ao)
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
    insert = 0;
    extract = 0;
    idata = 0;

    // Wait for global reset
    repeat (2) @(posedge clk);
    rst = 0;

    // Test case 1: Insert data
    @(posedge clk);
    insert = 1;
    idata = 32'h00000001;
    @(posedge clk);
    insert = 0;

    // Wait for a few clock cycles
    repeat (2) @(posedge clk);

    // Test case 2: Insert more data
    insert = 1;
    idata = 32'h00000002;
    @(posedge clk);
    insert = 0;

    // Wait for a few clock cycles
    repeat (2) @(posedge clk);

    // Test case 3: Extract data
    extract = 1;
    @(posedge clk);
    extract = 0;

    // Wait for a few clock cycles
    repeat (2) @(posedge clk);

    // Test case 4: Insert and extract alternately
    repeat (4) begin
      insert = 1;
      idata = $random;
      @(posedge clk);
      insert = 0;
      repeat (2) @(posedge clk);
      extract = 1;
      @(posedge clk);
      extract = 0;
      repeat (2) @(posedge clk);
    end

    // Test case 5: Reset the module
    rst = 1;
    repeat (2) @(posedge clk);
    rst = 0;

    // Wait for a few clock cycles
    repeat (2) @(posedge clk);

    // Finish simulation
    $finish;
  end

  // Monitor
  initial begin
    $monitor("Time=%0t rst=%b insert=%b extract=%b idata=%h even=%b odd=%b bo=%h ao=%h",
             $time, rst, insert, extract, idata, even, odd, bo, ao);
  end

endmodule