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
  parameter KEY_WIDTH=8; 
  parameter DATA_WIDTH=32;

  logic clk, rst, ivalid;
  logic [KEY_WIDTH+DATA_WIDTH-1:0] idata;
  logic irdy;
  logic ovalid;
  logic [KEY_WIDTH+DATA_WIDTH-1:0] odata;
  logic ordy;

  systolic_array #(
    .QUEUE_SIZE(QUEUE_SIZE),
    .KEY_WIDTH(KEY_WIDTH),
    .DATA_WIDTH(DATA_WIDTH)
  ) DUV (
    .clk(clk),
    .rst(rst),
    .ivalid(ivalid),
    .idata(idata),
    .irdy(irdy),
    .ovalid(ovalid),
    .odata(odata),
    .ordy(ordy)
  );

  task insert (input logic [KEY_WIDTH+DATA_WIDTH-1:0] kv);
    idata = kv;
    ivalid = 1;
    while (!irdy) @(posedge clk);
    @(posedge clk);
    ivalid = 0;
  endtask: insert

  task extract ();
    ordy = 1;
    while (!ovalid) @(posedge clk);
    @(posedge clk) #1;
    ordy = 0;
  endtask: extract

  always begin
    clk <= 0;
    #5; clk <= ~clk;
  end

  initial begin
    rst = 1;
    ivalid = 0;
    idata = 0;
    ordy = 0;

    repeat (2) @(posedge clk);
    rst = 0;
    @(posedge clk);
    insert(40'h111);
    repeat (4) @(posedge clk);
    insert(40'h202);
    @(posedge clk);
    insert(40'h143);
    repeat (3) @(posedge clk);
    insert(40'h304);
    repeat (10) @(posedge clk);
    extract();
    repeat (3) @(posedge clk);
    insert(40'h155);
    repeat (8) @(posedge clk);
    extract();
    repeat (5) @(posedge clk);
   $stop;
  end

endmodule
