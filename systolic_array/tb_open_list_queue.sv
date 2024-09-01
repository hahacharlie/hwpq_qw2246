/* verilator lint_off UNUSEDSIGNAL */

`timescale 1ns / 1ps
`define CLK_PERIOD 10

module tb_open_list_queue ();

  localparam QUEUE_SIZE = 8;
  localparam DATA_WIDTH = 32;
  localparam MAP_WIDTH = 16;
  localparam MAP_HEIGHT = 16;

  logic                  CLK;
  logic                  RSTn;

  /* control signals */
  logic                  i_wrt;  // enqueue
  logic                  i_read;  // dequeue
  logic                  i_valid;  // ready for next instruction
  logic [DATA_WIDTH-1:0] i_node_f;

  /* Output control signals */
  logic                  o_ready_deq;  // read ready flag
  logic                  o_ready_enq;  // write ready flag
  logic                  o_ready_rep;  // replace ready flag
  logic                  o_full;
  logic                  o_empty;
  logic                  o_valid;
  logic [DATA_WIDTH-1:0] o_node_f;

  open_list_queue #(QUEUE_SIZE, DATA_WIDTH, MAP_WIDTH, MAP_HEIGHT) u_open_list_queue (
      .CLK(CLK),
      .RSTn(RSTn),
      .i_wrt(i_wrt),
      .i_read(i_read),
      .i_valid(i_valid),
      .i_node_f(i_node_f),
      .o_ready_enq(o_ready_deq),
      .o_ready_deq(o_ready_enq),
      .o_ready_rep(o_ready_rep),
      .o_full(o_full),
      .o_empty(o_empty),
      .o_valid(o_valid),
      .o_node_f(o_node_f)
  );

  initial begin : CLK_GENERATION
    CLK = 0;
    forever #(`CLK_PERIOD / 2) CLK = !CLK;
  end

  initial begin : RST_GENERATION
    RSTn = 1;
    #1 RSTn = 0;
    repeat (2) @(negedge CLK);
    RSTn = 1;
  end

  initial begin : TEST

    $dumpfile("tb_open_list_queue.vcd");
    $dumpvars(0, tb_open_list_queue);

    i_wrt = 0;
    i_read = 0;
    i_valid = 0;
    i_node_f = 0;

    @(posedge RSTn);
    @(posedge CLK);

    // Enqueue operations
    write(5);
    write(2);
    write(11);
    write(14);
    write(10);
    write(3);
    write(7);
    write(1);

    // Dequeue operations and validate order
    read_and_check(1);
    read_and_check(2);
    read_and_check(3);
    read_and_check(5);
    read_and_check(7);
    read_and_check(10);
    read_and_check(11);
    read_and_check(14);

    $finish();
  end

  task write(input int i_data_f);
    if (o_full) $display("Write data: %d | Warning - The queue is full", i_data_f);
    else $display("Write data: %d", i_data_f);

    i_wrt = 1;
    i_node_f = i_data_f;
    i_valid = 1;

    @(posedge CLK);

    i_wrt = 0;

    @(posedge CLK);

  endtask

  task read_and_check(input int expected_f);
    i_read = 1;

    if (o_valid) begin
      $display("Read data: %d", o_node_f);
      assert (o_node_f == expected_f)
      else $error("Assertion failed: Expected %d, got %d", expected_f, o_node_f);
    end else begin
      $display("Error - The queue is empty");
      assert (0)
      else $error("Assertion failed: Expected %d, but queue was empty", expected_f);
    end

    repeat (2) @(posedge CLK);

    i_read = 0;

    @(posedge CLK);

  endtask

endmodule
