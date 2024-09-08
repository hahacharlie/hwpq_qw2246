`timescale 1ns/1ps
//
// systolic_pq_sort3_tb: simple stimulus-only testbench for sort3
//

module systolic_array_sort3_tb;
  parameter KEY_WIDTH=8, DATA_WIDTH=4;
  logic [KEY_WIDTH+DATA_WIDTH-1:0] a, b, c;
  logic [KEY_WIDTH+DATA_WIDTH-1:0] minv, medv, maxv;
  systolic_array_sort3 #(.KEY_WIDTH(KEY_WIDTH), .DATA_WIDTH(DATA_WIDTH)) DUV (.a(a), .b(b), .c(c), .minv(minv), .medv(medv), .maxv(maxv));

  initial begin

    $dumpfile("sort3.vcd");
    $dumpvars(0, systolic_array_sort3_tb);

    $monitor("time-%t, a=%h b=%h c = %h | minv=%h medv=%h maxv=%h", $time, a, b, c, minv, medv, maxv);

    a = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}};
    #100;
    
    a = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b1}}}; 
    b = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b1}}};
    #100;

    a = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b1}}}; 
    b = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}};
    #100;

    a = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    b = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}}; 
    c = {{KEY_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}};
    #100;

    $stop;

  end

endmodule
