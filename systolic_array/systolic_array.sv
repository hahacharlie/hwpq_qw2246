`timescale 1ns / 1ps

//
//  Systolic Priority Queue
//

module systolic_array #(
    parameter QUEUE_SIZE = 8,
    parameter DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst,
    input logic insert,
    input logic extract,
    input logic [DATA_WIDTH-1:0] idata,
    output logic ovalid,
    output logic [DATA_WIDTH-1:0] odata
);

  localparam [DATA_WIDTH-1:0] PQINF = '{DATA_WIDTH{1'b1}};
  localparam [DATA_WIDTH-1:0] PQNEGINF = '{DATA_WIDTH{1'b0}};

  logic even, odd, even_en, odd_en;

  logic [DATA_WIDTH-1:0] a [0:QUEUE_SIZE-1];
  logic [DATA_WIDTH-1:0] b [0:QUEUE_SIZE-1];

  assign even_en = !insert && !extract && even;
  assign odd_en = !insert && !extract && odd;

  systolic_array_proc0 #(
      .QUEUE_SIZE(QUEUE_SIZE),
      .DATA_WIDTH(DATA_WIDTH)
  ) U_PROC0 (
      .clk(clk),
      .rst(rst),
      .insert(insert),
      .extract(extract),
      .idata(idata),
      .even(even),
      .odd(odd),
      .bo(b[0]),
      .ao(a[0])
  );

  genvar i;
  generate
    for (i = 1; i < QUEUE_SIZE; i = i + 1) begin : gen_systolic_array_proc
      systolic_array_proc #(
          .DATA_WIDTH(DATA_WIDTH)
      ) U_PROC (
          .clk(clk),
          .rst(rst),
          .en((i % 2 == 1) ? odd_en : even_en),
          .b_previous_i(b[i-1]),
          .b_i(b[i]),
          .a_previous_i(a[i-1]),
          .a_i(a[i]),
          .b_previous_o(b[i-1]),
          .b_o(b[i]),
          .a_previous_o(a[i-1]),
          .a_o(a[i])
      );
    end
  endgenerate

  // can't read while a write is underway
  assign ovalid = (a[0] != PQINF) && (a[0] != PQNEGINF) && even;
  assign odata  = (ovalid) ? a[0] : PQNEGINF;

endmodule : systolic_array

