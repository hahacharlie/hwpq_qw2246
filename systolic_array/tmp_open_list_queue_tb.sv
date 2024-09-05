/* verilator lint_off UNUSEDSIGNAL */
module tmp_open_list_queue_tb;

  // Parameters
  parameter length = 8;
  parameter width = 32;

  // Inputs
  logic clk;
  logic reset;
  logic insert;
  logic pop;
  logic [width-1:0] in_f_value;

  // Outputs
  logic [width-1:0] out_f_value;
  logic empty;
  logic full;

  // Instantiate the Unit Under Test (UUT)
  tmp_open_list_queue #(
    .length(length),
    .width(width)
  ) uut (
    .clk(clk),
    .reset(reset),
    .insert(insert),
    .pop(pop),
    .in_f_value(in_f_value),
    .out_f_value(out_f_value),
    .empty(empty),
    .full(full)
  );

  // Clock generation
  initial begin
    clk = 0;
    reset = 1;
    forever #5 clk = ~clk; // 10ns period
  end

  // Test sequence
  initial begin
    // Initialize Inputs
    insert = 0;
    pop = 0;
    in_f_value = 0;

    $dumpfile("tmp_open_list_queue_tb.vcd");
    $dumpvars(0, tmp_open_list_queue_tb);

    // Wait for global reset
    @(posedge clk);
    reset = 0;

    // Insert fixed elements
    @(posedge clk);
    insert = 1;
    in_f_value = 32'd25;
    @(posedge clk);

    @(posedge clk);
    in_f_value = 32'd82;
    @(posedge clk);

    @(posedge clk);
    in_f_value = 32'd1;
    @(posedge clk);

    @(posedge clk);
    in_f_value = 32'd3;
    @(posedge clk);

    @(posedge clk);
    in_f_value = 32'd4;
    @(posedge clk);

    @(posedge clk);
    in_f_value = 32'd5;
    @(posedge clk);

    @(posedge clk);
    in_f_value = 32'd6;
    @(posedge clk);

    @(posedge clk);
    in_f_value = 32'd7;
    @(posedge clk);

    // this should not be inserted as the queue is full
    @(posedge clk);
    in_f_value = 32'd8;
    @(posedge clk);

    @(posedge clk);
    insert = 0;

    // Pop elements
    for (int i = 0; i < length; i++) begin
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
