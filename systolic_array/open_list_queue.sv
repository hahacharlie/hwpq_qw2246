module open_list_queue #(
    parameter QUEUE_SIZE = 8,  // Number of slots in each queue
    parameter DATA_WIDTH = 32  // Data width for node f values
) (
    input logic CLK,
    input logic RSTn,

    /* Input control signals */
    input logic i_wrt,  // enqueue
    input logic i_read,  // dequeue
    input logic i_valid,  // ready for next instruction
    input logic [DATA_WIDTH-1:0] i_node_f,  // Node data inputs

    /* Output control signals */
    output logic o_full,  // OB full
    output logic o_empty,  // OB empty
    output logic o_valid,  // OB[0] valid
    output logic [DATA_WIDTH-1:0] o_node_f  // Node data outputs
);

  localparam l_bits = $clog2(QUEUE_SIZE);

  logic [(l_bits+1):0] next_size, curr_size;

  logic [QUEUE_SIZE-1:0][DATA_WIDTH-1:0] inQueue, nextInQueue;
  logic [QUEUE_SIZE-1:0][DATA_WIDTH-1:0] outQueue, nextOutQueue;

  logic [QUEUE_SIZE-1:0] inQueueValid;
  logic [QUEUE_SIZE-1:0] nextInQueueValid;
  logic [QUEUE_SIZE-1:0] outQueueValid;
  logic [QUEUE_SIZE-1:0] nextOutQueueValid;

  logic [QUEUE_SIZE-1:0] lessThanPrevInQueue;
  logic [QUEUE_SIZE-1:0] lessThanNextInQueue;
  logic [QUEUE_SIZE-1:0] lessThanSameOutQueue;
  logic [QUEUE_SIZE-1:0] lessThanNextOutQueue;
  logic [QUEUE_SIZE-1:0] lessThanNextNextOutQueue;

  integer i, j;

  assign o_full   = next_size == QUEUE_SIZE;
  assign o_empty  = next_size == '0;

  assign o_node_f = outQueue[0];
  assign o_valid  = outQueueValid[0];

  always_ff @(posedge CLK) begin
    if (!RSTn) begin
      curr_size <= '0;
      inQueueValid <= '0;
      outQueueValid <= '0;
      for (i = 0; i < QUEUE_SIZE; i += 1) begin
        inQueue[i]  <= '1;
        outQueue[i] <= '1;
      end
    end else begin
      curr_size     <= next_size;
      inQueue       <= nextInQueue;
      inQueueValid  <= nextInQueueValid;
      outQueue      <= nextOutQueue;
      outQueueValid <= nextOutQueueValid;
    end
  end

  always_comb begin
    // defaults
    next_size = curr_size;
    nextInQueue = '1;
    nextInQueueValid = '0;
    nextOutQueue = outQueue;
    nextOutQueueValid = outQueueValid;

    // push and pop operation control
    if (i_wrt && i_read) begin
      next_size = curr_size;
      if ((i_node_f < outQueue[0]) && (i_node_f < outQueue[1]) && (!inQueueValid[0] || (i_node_f < inQueue[0]))) begin
        // enqueue directly into outQueue[0]
        nextOutQueue[0] = i_node_f;
        nextOutQueueValid[0] = 1;
      end else begin
        // enqueue into inQueue[0]
        nextInQueue[0] = i_node_f;
        nextInQueueValid[0] = 1;
        // dequeue outQueue[0]
        nextOutQueue[0] = '1;
        nextOutQueueValid[0] = 0;
      end
    end else if (i_wrt) begin
      next_size = curr_size + 1;
      if ((i_node_f < outQueue[0]) && (i_node_f < outQueue[1]) && (!inQueueValid[0] || (i_node_f < inQueue[0]))) begin
        // enqueue directly into outQueue[0]
        nextOutQueue[0] = i_node_f;
        nextOutQueueValid[0] = 1;
        // Bump outQueue[0] into inQueue[0]
        nextInQueue[0] = outQueue[0];
        nextInQueueValid[0] = outQueueValid[0];
      end else begin
        // enqueue into inQueue[0]
        nextInQueue[0] = i_node_f;
        nextInQueueValid[0] = 1;
      end
    end else if (i_read) begin
      next_size = curr_size - 1;
      nextOutQueue[0] = '1;
      nextOutQueueValid[0] = 0;
    end

    // Initialize the comparators
    lessThanPrevInQueue      = '0;
    lessThanNextInQueue      = '0;
    lessThanSameOutQueue     = '0;
    lessThanNextOutQueue     = '0;
    lessThanNextNextOutQueue = '0;

    // Comparsion for each node in queue
    for (j = 0; j < QUEUE_SIZE; j += 1) begin
      lessThanPrevInQueue[j] = (j > 0) ? (inQueue[j] < inQueue[j-1] ) : !i_wrt || (inQueue[j] <= i_node_f);
      lessThanNextInQueue[j] = (j < QUEUE_SIZE - 1) ? (inQueue[j] < inQueue[j+1]) : 1;
      lessThanSameOutQueue[j] = (inQueue[j] < outQueue[j]);
      lessThanNextOutQueue[j] = (j < QUEUE_SIZE - 1) ? (inQueue[j] < outQueue[j+1]) : 1;
      lessThanNextNextOutQueue[j] = (j < QUEUE_SIZE - 2) ? (inQueue[j] < outQueue[j+2]) : 1;
    end

    // Perform sorting based on comaprator result
    for (j = 0; j < QUEUE_SIZE - 1; j += 1) begin
      if (lessThanSameOutQueue[j] && lessThanNextOutQueue[j] && lessThanPrevInQueue[j]) begin
        // Insert inQueue into empty outQueue slot
        nextOutQueue[j] = inQueue[j];
        nextOutQueueValid[j] = inQueueValid[j];
      end else if (lessThanNextOutQueue[j] && lessThanNextInQueue[j] && lessThanNextNextOutQueue[j]) begin
        // Swap inQueue and outQueue
        nextInQueue[j+1] = outQueue[j+1];
        nextInQueueValid[j+1] = outQueueValid[j+1];
        nextOutQueue[j+1] = inQueue[j];
        nextOutQueueValid[j+1] = inQueueValid[j];
      end else if ((j == QUEUE_SIZE - 2) && !outQueueValid[j+1] && inQueueValid[j+1]) begin
        nextOutQueue[j+1] = inQueue[j+1];
        nextOutQueueValid[j+1] = inQueueValid[j+1];
      end else begin
        // Shift inQueue down
        nextInQueue[j+1] = inQueue[j];
        nextInQueueValid[j+1] = inQueueValid[j];
      end
    end

    // Shift outQueue length forward if there is a gap
    //! I don't think this is correct.
    for (j = 0; j < QUEUE_SIZE - 1; j += 1) begin
      if (!outQueueValid[j] && !nextOutQueueValid[j]) begin
        nextOutQueue[j] = outQueue[j+1];
        nextOutQueueValid[j] = outQueueValid[j+1];
        nextOutQueue[j+1] = '1;
        nextOutQueueValid[j+1] = 0;
      end
    end
  end

endmodule
