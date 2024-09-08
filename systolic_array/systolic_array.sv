module systolic_array #(
    parameter QUEUE_SIZE = 4,
    parameter KEY_WIDTH = 8,
    parameter DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst,
    input logic ivalid,
    input logic [KEY_WIDTH+DATA_WIDTH-1:0] idata,
    output logic irdy,
    output logic ovalid,
    output logic [KEY_WIDTH+DATA_WIDTH-1:0] odata,
    input logic ordy
);

  localparam [KEY_WIDTH+DATA_WIDTH-1:0] PQINF = '{KEY_WIDTH{1'b1}, DATA_WIDTH{1'b0}};
  localparam [KEY_WIDTH+DATA_WIDTH-1:0] PQNEGINF = '{KEY_WIDTH{1'b0}, DATA_WIDTH{1'b0}};

  logic even, odd;

  logic [KEY_WIDTH+DATA_WIDTH-1:0]
      a0, a0x, a1, a1x, a2, a2x, a3, a3x, a4, a4x, b0, b1, b2, b3, b4;

  systolic_array_proc0 #(
      .QUEUE_SIZE(QUEUE_SIZE),
      .KEY_WIDTH(KEY_WIDTH),
      .DATA_WIDTH(DATA_WIDTH)
  ) U_PROC0 (
      .clk(clk),
      .rst(rst),
      .even(even),
      .odd(odd),
      .ivalid(ivalid),
      .idata(idata),
      .irdy(irdy),
      .ovalid(ovalid),
      .ordy(ordy),
      .bo(b0),
      .ao(a0)
  );

  systolic_array_proc #(
      .KEY_WIDTH(KEY_WIDTH),
      .DATA_WIDTH(DATA_WIDTH)
  ) U_PROC1 (
      .clk,
      .rst,
      .en(odd),
      .b_i (b0),
      .a_i (a0),
      .a_previous_i(PQINF),
      .b_o (b1),
      .a_o (a1),
      .a_previous_o(a0x)
  );

  systolic_array_proc #(
      .KEY_WIDTH(KEY_WIDTH),
      .DATA_WIDTH(DATA_WIDTH)
  ) U_PROC2 (
      .clk,
      .rst,
      .en(even),
      .b_i (b1),
      .a_i (a1),
      .a_previous_i(a0x),
      .b_o (b2),
      .a_o (a2),
      .a_previous_o(a1x)
  );

  systolic_array_proc #(
      .KEY_WIDTH(KEY_WIDTH),
      .DATA_WIDTH(DATA_WIDTH)
  ) U_PROC3 (
      .clk,
      .rst,
      .en(odd),
      .b_i (b2),
      .a_i (a2),
      .a_previous_i(a1x),
      .b_o (b3),
      .a_o (a3),
      .a_previous_o(a2x)
  );

  systolic_array_proc #(
      .KEY_WIDTH(KEY_WIDTH),
      .DATA_WIDTH(DATA_WIDTH)
  ) U_PROC4 (
      .clk,
      .rst,
      .en(even),
      .b_i (b3),
      .a_i (a3),
      .a_previous_i(a2x),
      .b_o (b4),
      .a_o (a4),
      .a_previous_o(a3x)
  );

  // can't read while a write is underway
  assign ovalid = (a1 != PQINF) && even && !(ivalid && irdy);
  assign odata  = a1;

endmodule : systolic_array
