`timescale 1ns / 1ps

//
// Sort three values into minimum, median, and maximum values
//

module systolic_array_sort3 #(
    parameter DATA_WIDTH=32
) (
    input logic [DATA_WIDTH-1:0] a, 
    input logic [DATA_WIDTH-1:0] b, 
    input logic [DATA_WIDTH-1:0] c,
    output logic [DATA_WIDTH-1:0] minv, medv, maxv
);

  // Some internal used constants
  // localparam [DATA_WIDTH-1:0] PQINF = '{DATA_WIDTH{1'b1}};
  // localparam [KEY_WIDTH+DATA_WIDTH-1:0] PQNEGINF = '{KEY_WIDTH{1'b0}, DATA_WIDTH{1'b0}};

  logic a_gt_b, a_gt_c, b_gt_c;

  // extract the keys
  assign a_gt_b = a > b;
  assign a_gt_c = a > c;
  assign b_gt_c = b > c;

  always_comb begin
    case ({a_gt_b, a_gt_c, b_gt_c})
      3'b000 : begin
        minv = a;
        medv = b;
        maxv = c;
      end
      3'b001 : begin
        minv = a;
        medv = c;
        maxv = b;
      end
      3'b100 : begin
        minv = b;
        medv = a;
        maxv = c;
      end
      3'b011 : begin
        minv = c;
        medv = a;
        maxv = b;
      end
      3'b110 : begin
        minv = b;
        medv = c;
        maxv = a;
      end
      3'b111 : begin
        minv = c;
        medv = b;
        maxv = a;
      end
      // remaining cases 3'b010, 3'b101 cannot occur! If happened, revoke keys
      // default : begin       
      //   minv = PQINF;
      //   medv = PQINF;
      //   maxv = PQINF;
      // end
    endcase
  end

endmodule : systolic_array_sort3
