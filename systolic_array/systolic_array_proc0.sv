//
//  Processing node 0 for Lieserson's Systolic Priority Queue
//

module systolic_array_proc0 #(
    parameter QUEUE_SIZE=4,
    parameter KEY_WIDTH=8,
    parameter DATA_WIDTH=32
) (
    input logic clk, rst,
    input logic ivalid,
    input logic ovalid,
    input logic ordy,
    input logic [KEY_WIDTH+DATA_WIDTH-1:0] idata,
    output logic even, odd,
    output logic irdy,
    output logic [KEY_WIDTH+DATA_WIDTH-1:0] bo, ao
);

    // may want to move these to the main module?
    localparam [KEY_WIDTH+DATA_WIDTH-1:0] PQINF = '{KEY_WIDTH{1'b1}, DATA_WIDTH{1'b0}};
    localparam [KEY_WIDTH+DATA_WIDTH-1:0] PQNEGINF = '{KEY_WIDTH{1'b0}, DATA_WIDTH{1'b0}};

    //--------------------------------------------------
    // Generate odd, even enables
    //--------------------------------------------------

    always @(posedge clk)
      if (rst) odd <= 0;
      else odd <= !odd;

    assign even = !odd;

    //--------------------------------------------------
    // write logic to place stuff in the queue
    //--------------------------------------------------

    logic [$clog2(QUEUE_SIZE):0] pq_count;

    assign irdy = (pq_count <= QUEUE_SIZE) && even;

    always_ff @(posedge clk) begin
      if (rst)
        begin
          bo <= PQINF;
          ao <= PQNEGINF;
          pq_count <= 0;
        end
      else if (ovalid && ordy )
        begin
          bo <= PQINF;
          ao <= PQINF;
          pq_count <= pq_count - 1;
        end
      else if (ivalid && irdy )
        begin
          bo <= idata;
          ao <= PQNEGINF;
          pq_count <= pq_count + 1;
        end
      else
        begin // default - insert "infinite" weight
          bo <= PQINF;
          ao <= PQNEGINF;
        end
    end

endmodule: systolic_array_proc0
