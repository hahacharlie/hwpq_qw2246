module tmp_open_list_queue #(
    parameter QUEUE_SIZE = 4,
    parameter DATA_WIDTH = 32
) (
    input logic CLK,
    input logic RSTn,

    /* Input control signals */
    input logic i_wrt,  // enqueue
    input logic i_read,  // dequeue
    input logic i_valid,  // ready for next instruction
    input logic [DATA_WIDTH-1:0] i_node_f,  // node data input 

    /* Output control signals */
    output logic o_ready_deq,  // read ready flag
    output logic o_ready_enq,  // write ready flag
    output logic o_ready_rep,  // replace ready flag
    output logic o_full,  // OB full
    output logic o_empty,  // OB empty
    output logic o_valid,  // OB[0] valid
    output logic [DATA_WIDTH-1:0] o_node_f  // node data output
);

  localparam QUEUE_SIZE_BITS_NEEDED = $clog2(QUEUE_SIZE);

  // Internal buffers
  logic   [          DATA_WIDTH-1:0] queue       [0:QUEUE_SIZE-1];
  logic   [          QUEUE_SIZE-1:0] queue_valid;

  // Queue pointers and size
  logic   [QUEUE_SIZE_BITS_NEEDED:0] queue_size;
  logic                              queue_full;
  logic                              queue_empty;

  integer                            i;

  // Output assignments
  assign o_full      = queue_full;
  assign o_empty     = queue_empty;
  assign o_valid     = queue_valid[0];
  assign o_node_f    = queue[0];
  assign o_ready_enq = !queue_full;
  assign o_ready_deq = !queue_empty;

  // Queue full and empty indicators
  always_comb begin
    queue_full  = (queue_size == QUEUE_SIZE);
    queue_empty = (queue_size == 0);
  end

  // Sequential logic for queue operations
  always_ff @(posedge CLK or negedge RSTn) begin
    if (!RSTn) begin
      // Reset state
      queue_size <= 0;
      for (i = 0; i < QUEUE_SIZE; i++) begin
        queue[i]       <= '0;
        queue_valid[i] <= 1'b0;
      end
    end else begin
      if (i_wrt && o_ready_enq && i_valid) begin
        // Enqueue operation
        // Insert the new node into the queue maintaining sorted order
        integer insert_pos;
        insert_pos = queue_size;

        // Find the correct position to insert
        for (i = 0; i < queue_size; i++) begin
          if (i_node_f < queue[i]) begin
            insert_pos = i;
            break;
          end
        end

        // Shift elements to make room for the new node
        for (i = queue_size; i > insert_pos; i--) begin
          queue[i]       <= queue[i-1];
          queue_valid[i] <= queue_valid[i-1];
        end

        // Insert the new node
        queue[insert_pos]       <= i_node_f;
        queue_valid[insert_pos] <= 1'b1;

        // Update queue size
        if (!i_read) begin
          queue_size <= queue_size + 1;
        end
      end

      if (i_read && o_ready_deq) begin
        // Dequeue operation
        if (i_wrt && o_ready_enq && i_valid) begin
          // If enqueue and dequeue happen simultaneously, size remains the same
          // Dequeue is already handled by shifting during enqueue
        end else begin
          // Shift elements to remove the first element
          for (i = 0; i < queue_size - 1; i++) begin
            queue[i]       <= queue[i+1];
            queue_valid[i] <= queue_valid[i+1];
          end
          // Invalidate the last element
          queue[queue_size-1]       <= '0;
          queue_valid[queue_size-1] <= 1'b0;

          // Update queue size
          queue_size                <= queue_size - 1;
        end
      end

      if (!i_wrt && !i_read) begin
        // No operation, maintain current state
        for (i = 0; i < QUEUE_SIZE; i++) begin
          queue[i]       <= queue[i];
          queue_valid[i] <= queue_valid[i];
        end
      end
    end
  end

endmodule
