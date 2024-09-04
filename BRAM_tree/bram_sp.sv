/*
  Block RAM (Single-Port Block RAM), Sxtracted from Vivado Verilog Examples
  File: rams_sp_rom
*/
module bram_sp #(
    parameter QUEUE_SIZE = 4,
    parameter WIDTH = 32
) (
    input logic clk,
    input logic we,
    input logic [$clog2(QUEUE_SIZE)-1:0] addr,
    input logic [WIDTH-1:0] di,
    output logic [WIDTH-1:0] dout
);

  reg [WIDTH-1:0] ram[$clog2(QUEUE_SIZE):0];

  initial begin
    // ram[63] = 32'h0200A;
    // ram[62] = 32'h00300;
    // ram[61] = 32'h08101;
    // ram[60] = 32'h04000;
    // ram[59] = 32'h08601;
    // ram[58] = 32'h0233A;
    // ram[57] = 32'h00300;
    // ram[56] = 32'h08602;
    // ram[55] = 32'h02310;
    // ram[54] = 32'h0203B;
    // ram[53] = 32'h08300;
    // ram[52] = 32'h04002;
    // ram[51] = 32'h08201;
    // ram[50] = 32'h00500;
    // ram[49] = 32'h04001;
    // ram[48] = 32'h02500;
    // ram[47] = 32'h00340;
    // ram[46] = 32'h00241;
    // ram[45] = 32'h04002;
    // ram[44] = 32'h08300;
    // ram[43] = 32'h08201;
    // ram[42] = 32'h00500;
    // ram[41] = 32'h08101;
    // ram[40] = 32'h00602;
    // ram[39] = 32'h04003;
    // ram[38] = 32'h0241E;
    // ram[37] = 32'h00301;
    // ram[36] = 32'h00102;
    // ram[35] = 32'h02122;
    // ram[34] = 32'h02021;
    // ram[33] = 32'h00301;
    // ram[32] = 32'h00102;
    // ram[31] = 32'h02222;
    // ram[30] = 32'h04001;
    // ram[29] = 32'h00342;
    // ram[28] = 32'h0232B;
    // ram[27] = 32'h00900;
    // ram[26] = 32'h00302;
    // ram[25] = 32'h00102;
    // ram[24] = 32'h04002;
    // ram[23] = 32'h00900;
    // ram[22] = 32'h08201;
    // ram[21] = 32'h02023;
    // ram[20] = 32'h00303;
    // ram[19] = 32'h02433;
    // ram[18] = 32'h00301;
    // ram[17] = 32'h04004;
    // ram[16] = 32'h00301;
    // ram[15] = 32'h00102;
    // ram[14] = 32'h02137;
    // ram[13] = 32'h02036;
    // ram[12] = 32'h00301;
    // ram[11] = 32'h00102;
    // ram[10] = 32'h02237;
    // ram[9]  = 32'h04004;
    // ram[8]  = 32'h00304;
    // ram[7]  = 32'h04040;
    // ram[6]  = 32'h02500;
    // ram[5]  = 32'h02500;
    // ram[4]  = 32'h02500;
    // ram[3] = 32'h0030D;
    ram[2] = 32'h02341;
    ram[1] = 32'h08201;
    ram[0] = 32'h0400D;
  end

  always @(posedge clk) begin
    if (we) begin
      ram[addr] <= di;
      dout <= ram[addr];
    end
  end

endmodule
