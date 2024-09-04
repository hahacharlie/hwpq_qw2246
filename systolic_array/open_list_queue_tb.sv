/* verilator lint_off UNUSEDSIGNAL */
module open_list_queue_tb;

  // Parameters
  parameter QUEUE_SIZE = 8;
  parameter DATA_WIDTH = 32;

  // Inputs
  logic clk;
  logic insert;
  logic pop;
  logic [DATA_WIDTH-1:0] in_data;
  logic [DATA_WIDTH-1:0] in_f_value;

  // Outputs
  logic [DATA_WIDTH-1:0] out_data;
  logic [DATA_WIDTH-1:0] out_f_value;
  logic empty;
  logic full;

  // Instantiate the Unit Under Test (UUT)
  open_list_queue #(
    .QUEUE_SIZE(QUEUE_SIZE),
    .DATA_WIDTH(DATA_WIDTH)
  ) uut (
    .clk(clk),
    .insert(insert),
    .pop(pop),
    .in_data(in_data),
    .in_f_value(in_f_value),
    .out_data(out_data),
    .out_f_value(out_f_value),
    .empty(empty),
    .full(full)
  );

  // Clock generation
  initial begin
    clk = 0;
    forever #5 clk = ~clk; // 10ns period
  end

  // Test sequence
  initial begin
    // Initialize Inputs
    insert = 0;
    pop = 0;
    in_data = 0;
    in_f_value = 0;

    $dumpfile("open_list_queue_tb.vcd");
    $dumpvars(0, open_list_queue_tb);

    // Wait for global reset
    @(posedge clk);

    // Insert fixed elements
    @(posedge clk);
    insert = 1;
    in_data = 0;
    in_f_value = 25;

    @(posedge clk);
    in_data = 1;
    in_f_value = 82;

    @(posedge clk);
    in_data = 2;
    in_f_value = 1;

    @(posedge clk);
    in_data = 3;
    in_f_value = 23;

    @(posedge clk);
    in_data = 4;
    in_f_value = 52;

    @(posedge clk);
    in_data = 5;
    in_f_value = 67;

    @(posedge clk);
    in_data = 6;
    in_f_value = 92;

    @(posedge clk);
    in_data = 7;
    in_f_value = 32;

    // this should not be inserted as the queue is full
    @(posedge clk);
    in_data = 8;
    in_f_value = 10;

    @(posedge clk);
    insert = 0;

    // Pop elements
    for (int i = 0; i < QUEUE_SIZE; i++) begin
      @(posedge clk);
      pop = 1;
    end
    @(posedge clk);
    pop = 0;

    // Finish simulation
    repeat (2) @(posedge clk);
    $finish;
  end

  // Monitor outputs
  // initial begin
  //   $monitor("Time=%0t, insert=%b, pop=%b, in_data=%h, in_f_value=%h, out_data=%h, out_f_value=%h, empty=%b, full=%b",
  //            $time, insert, pop, in_data, in_f_value, out_data, out_f_value, empty, full);
  // end

endmodule
