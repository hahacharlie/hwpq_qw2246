module bram_tree_tb;

  // Parameters
  // parameter TREE_DEPTH = 4;
  // parameter LEVEL_SIZE = 2**TREE_DEPTH;
  parameter DATA_WIDTH = 32;
  parameter CLK_PERIOD = 10;  // 10ns clock period

  // Signals
  logic clk;
  logic rst;
  logic replace;
  logic [DATA_WIDTH-1:0] new_item;
  logic [DATA_WIDTH-1:0] top_item;

  // Instantiate the Unit Under Test (UUT)
  bram_tree uut (
      .clk(clk),
      .rst(rst),
      .replace(replace),
      .new_item(new_item),
      .top_item(top_item)
  );

  // Clock generation
  always #(CLK_PERIOD / 2) clk <= ~clk;

  // Test procedure
  initial begin
    // Initialize signals
    clk = 0;
    rst = 0;
    replace = 0;
    new_item = 0;

    // Apply reset for a few clock cycles
    rst = 1;
    repeat (4) @(posedge clk);
    rst = 0;

    // Initialize the queue with ascending numbers
    for (int i = 0; i < 16; i++) begin
      replace  = 1;
      new_item = (i + 1) * 10;
      @(posedge clk);
      replace = 0;
      repeat (5) @(posedge clk);
    end

    // Perform 5 replace operations with random numbers
    for (int i = 0; i < 5; i++) begin
      replace  = 1;
      new_item = $urandom_range(1, 250);  // Random number between 1 and 1000
      @(posedge clk);
      replace = 0;
      repeat (5) @(posedge clk);  // Wait for the replace operation to complete

      // Display the replaced value and the new input
      $display("Replace %0d: Removed %0d, Inserted %0d", i + 1, top_item, new_item);
    end

    // End simulation
    repeat (10) @(posedge clk);
    $finish;
  end

  // Monitor outputs
  always @(posedge clk) begin
    $display("Time %0t: Valid output - %0d", $time, top_item);
  end

endmodule
