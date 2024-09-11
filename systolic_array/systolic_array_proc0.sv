`timescale 1ns / 1ps

//
//  Processing node 0 for Lieserson's Systolic Priority Queue
//

module systolic_array_proc0 #(
    parameter QUEUE_SIZE = 4,
    parameter DATA_WIDTH = 32
) (
    input logic clk, rst,
    input logic insert,
    input logic extract,
    input logic [DATA_WIDTH-1:0] idata,
    output logic even, odd,
    output logic [DATA_WIDTH-1:0] bo, ao
);

    // Some internal used constants
    localparam [DATA_WIDTH-1:0] PQINF = '{DATA_WIDTH{1'b1}};
    localparam [DATA_WIDTH-1:0] PQNEGINF = '{DATA_WIDTH{1'b0}};

    logic insert_ready;
    logic extract_ready;

    //--------------------------------------------------
    // Generate odd, even enables
    //--------------------------------------------------

    always @(posedge clk) begin
      if (rst) begin 
        odd <= 0;
      end else begin
        odd <= !odd;
      end
    end

    assign even = !odd;

    //--------------------------------------------------
    // write logic to place stuff in the queue
    //--------------------------------------------------

    logic [$clog2(QUEUE_SIZE):0] pq_count;

    assign insert_ready  = (pq_count <= QUEUE_SIZE) && even;
    assign extract_ready = (pq_count > 0) && even;

    always_ff @(posedge clk) begin
      if (rst) begin // Initially, all elements in the queue are positive infinity
        bo <= PQINF;
        ao <= PQINF;
        pq_count <= 0;
      end else if (extract) begin
        bo <= PQINF;
        ao <= PQINF;
        pq_count <= pq_count - 1;
      end else if (insert) begin
        bo <= idata;
        ao <= PQNEGINF;
        pq_count <= pq_count + 1;
      end
    end

endmodule: systolic_array_proc0
