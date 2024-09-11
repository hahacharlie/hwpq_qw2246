`timescale 1ns / 1ps

//
//  Processing node for Lieserson's Systolic Priority Queue
//

module systolic_array_proc #(
    parameter DATA_WIDTH=32
) (
    input logic clk, rst, en,
    input logic [DATA_WIDTH-1:0] b_previous_i, b_i, a_previous_i, a_i,
    output logic [DATA_WIDTH-1:0] b_previous_o, b_o, a_previous_o, a_o
);

  // Some internal used constants
  localparam [DATA_WIDTH-1:0] PQINF = '{DATA_WIDTH{1'b1}};
  localparam [DATA_WIDTH-1:0] PQNEGINF = '{DATA_WIDTH{1'b0}};
  
  // Some internal used variables
  logic [DATA_WIDTH-1:0] minv, medv, maxv;

  systolic_array_sort3 U_SORT3 (.a(b_previous_i), .b(a_i), .c(a_previous_i), .minv(minv), .medv(medv), .maxv(maxv));
  
  // assign a_previous_o = minv;

  always_ff @(posedge clk) begin
    if (rst) begin // Initially, all elements in the queue are positive infinity
      b_previous_o <= PQINF;
      b_o <= PQINF;
      a_previous_o <= PQINF;
      a_o <= PQINF;
    end else if (en) begin
      b_previous_o <= PQINF;
      b_o <= maxv;
      a_previous_o <= minv;
      a_o <= medv;
    end 
  end
 
endmodule: systolic_array_proc
