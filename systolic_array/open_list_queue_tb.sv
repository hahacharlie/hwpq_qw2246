module open_list_queue_tb;

  // Parameters
  parameter QUEUE_SIZE = 4;
  parameter DATA_WIDTH = 32;

  // Inputs
  logic clk;
  logic rst_n;
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
    .rst_n(rst_n),
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
    rst_n = 1;
    forever #5 clk = ~clk; // 10ns period
  end

  // Test sequence
  initial begin
    // Global reset
    @(posedge clk);

    // Initialize Inputs
    rst_n = 0;
    insert = 0;
    pop = 0;
    in_data = 32'd8;
    in_f_value = 32'd4;

    // Insert fixed elements
    @(posedge clk);
    insert = 1;

    @(posedge clk);
    pop = 1;

    // @(posedge clk);
    // in_f_value = 32'd82;
    // in_data = 32'd2;
    // @(posedge clk);

    // @(posedge clk);
    // in_f_value = 32'd1;
    // in_data = 32'd3;
    // @(posedge clk);

    // @(posedge clk);
    // in_f_value = 32'd3;
    // in_data = 32'd4;
    // @(posedge clk);

    // @(posedge clk);
    // in_f_value = 32'd4;
    // in_data = 32'd5;
    // @(posedge clk);

    // @(posedge clk);
    // in_f_value = 32'd5;
    // in_data = 32'd6;
    // @(posedge clk);

    // @(posedge clk);
    // in_f_value = 32'd6;
    // in_data = 32'd7;
    // @(posedge clk);

    // @(posedge clk);
    // in_f_value = 32'd7;
    // in_data = 32'd8;
    // @(posedge clk);

    // // this should not be inserted as the queue is full
    // @(posedge clk);
    // in_f_value = 32'd8;
    // in_data = 32'd9;
    // @(posedge clk);

    // @(posedge clk);
    // insert = 0;

    // // Pop elements
    // for (int i = 0; i < QUEUE_SIZE; i++) begin
    //   @(posedge clk);
    //   pop = 1;
    // end
    // @(posedge clk);
    // pop = 0;

    // Finish simulation
    repeat (2) @(posedge clk);
    $finish;
  end

endmodule
