`timescale 1ns / 1ps

//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 04/23/2020 03:43:43 PM
// Design Name:
// Module Name: systolic_pq_tb
// Project Name:
// Target Devices:
// Tool Versions:
// Description:
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////


module systolic_array_tb;

  parameter QUEUE_SIZE=4;
  parameter DATA_WIDTH=32;

  logic clk, rst;
  logic insert, extract;
  logic [DATA_WIDTH-1:0] idata;
  logic ovalid;
  logic [DATA_WIDTH-1:0] odata;

  systolic_array #(
    .QUEUE_SIZE(QUEUE_SIZE),
    .DATA_WIDTH(DATA_WIDTH)
  ) DUV (
    .clk(clk),
    .rst(rst),
    .insert(insert),
    .extract(extract),
    .idata(idata),
    .ovalid(ovalid),
    .odata(odata)
  );

  task insert_op (input logic [DATA_WIDTH-1:0] data);
    idata = data;
    insert = 1;
    @(posedge clk);
    idata = '{DATA_WIDTH{1'bx}};
    insert = 0;
  endtask: insert_op

  task extract_op ();
    extract = 1;
    @(posedge clk);
    extract = 0;
  endtask: extract_op

  always begin
    #5; clk <= ~clk;
  end

  initial begin
    clk = 1;
    rst = 1;
    insert = 0;
    extract = 0;
    repeat (5) @(posedge clk);
    rst = 0;

    // repeat (5) @(posedge clk);
    insert_op(10);
    repeat (5) @(posedge clk);
    insert_op(128);
    repeat (5) @(posedge clk);
    insert_op(55);
    repeat (5) @(posedge clk);
    extract_op();
    repeat (5) @(posedge clk);
    extract_op();
    repeat (5) @(posedge clk);
    $stop;
  end

endmodule
