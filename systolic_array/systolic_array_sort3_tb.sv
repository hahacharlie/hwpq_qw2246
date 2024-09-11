`timescale 1ns/1ps

//
// systolic_pq_sort3_tb: simple stimulus-only testbench for sort3
//

module systolic_array_sort3_tb;
  parameter DATA_WIDTH=32;
  logic [DATA_WIDTH-1:0] a, b, c;
  logic [DATA_WIDTH-1:0] minv, medv, maxv;
  systolic_array_sort3 #(.DATA_WIDTH(DATA_WIDTH)) DUV (.a(a), .b(b), .c(c), .minv(minv), .medv(medv), .maxv(maxv));

  initial begin

    // $dumpfile("sort3.vcd");
    // $dumpvars(0, systolic_array_sort3_tb);

    $monitor("time-%t, a=%h b=%h c = %h | minv=%h medv=%h maxv=%h", $time, a, b, c, minv, medv, maxv);

    repeat (10) begin
      a = $urandom_range(0, 120);
      b = $urandom_range(0, 120);
      c = $urandom_range(0, 120);
      #100;
    end

    $stop;

  end

endmodule
