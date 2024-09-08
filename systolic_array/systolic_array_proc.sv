//
//  Processing node for Lieserson's Systolic Priority Queue
//

module systolic_array_proc #(
    parameter KEY_WIDTH=8,
    parameter DATA_WIDTH=32
) (
    input logic clk, rst, en,
    input logic [KEY_WIDTH+DATA_WIDTH-1:0] b_i, a_i, a_previous_i,
    output logic [KEY_WIDTH+DATA_WIDTH-1:0] b_o, a_o, a_previous_o
);
  // Some internal used constants
  localparam [KEY_WIDTH+DATA_WIDTH-1:0] PQINF = '{KEY_WIDTH{1'b1}, DATA_WIDTH{1'b0}};
  localparam [KEY_WIDTH+DATA_WIDTH-1:0] PQNEGINF = '{KEY_WIDTH{1'b0}, DATA_WIDTH{1'b0}};
  
  // Some internal used variables
  logic [KEY_WIDTH+DATA_WIDTH-1:0] minv, medv, maxv;

  systolic_array_sort3 U_SORT3 (.a(a_i), .b(a_previous_i), .c(b_i), .minv(minv), .medv(medv), .maxv(maxv));
  
  assign a_previous_o = minv;

  always_ff @(posedge clk) begin
    if (rst) begin
      b_o <= PQINF;
      a_o <= PQNEGINF;
    end else if (en) begin
      b_o <= maxv;
      a_o <= medv;
    end else begin  // not enabled - exchange a
      a_o <= a_previous_i;
    end
  end
 
endmodule: systolic_array_proc
