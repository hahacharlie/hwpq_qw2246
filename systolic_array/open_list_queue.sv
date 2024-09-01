/* verilator lint_off UNUSEDPARAM */
/* verilator lint_off UNUSEDSIGNAL */

`timescale 1ns / 1ps

module open_list_queue #(
    parameter QUEUE_SIZE = 4,  // Number of slots in each queue
    parameter DATA_WIDTH = 32,  // Data width for node f values
    parameter MAP_WIDTH = 16,  // Width of the map
    parameter MAP_HEIGHT = 16,  // Height of the map
    parameter MAX_F = 32'hFFFFFFFF  // Maximum value for f
) (
    input logic CLK,
    input logic RSTn,

    /* Input control signals */
    input logic i_wrt,  // enqueue
    input logic i_read,  // dequeue
    input logic i_valid,  // ready for next instruction
    // Node data inputs
    input logic [DATA_WIDTH-1:0] i_node_f,
    // input logic [ MAP_WIDTH-1:0] i_node_i,
    // input logic [MAP_HEIGHT-1:0] i_node_j,

    /* Output control signals */
    output logic o_ready_deq,  // read ready flag
    output logic o_ready_enq,  // write ready flag
    output logic o_ready_rep,  // replace ready flag
    output logic o_full,  // OB full
    output logic o_empty,  // OB empty
    output logic o_valid,  // OB[0] valid
    // Node data outputs
    output logic [DATA_WIDTH-1:0] o_node_f
    // output logic [ MAP_WIDTH-1:0] o_node_i,
    // output logic [MAP_HEIGHT-1:0] o_node_j
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

    // comparsion for each node in queue
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
    for (j = 0; j < QUEUE_SIZE - 1; j += 1) begin
      if (!outQueueValid[j] && !nextOutQueueValid[j]) begin
        nextOutQueue[j] = outQueue[j+1];
        nextOutQueueValid[j] = outQueueValid[j+1];
        nextOutQueue[j+1] = '1;
        nextOutQueueValid[j+1] = 0;
      end
    end
  end

  //========================================================================
  // ready logic
  //========================================================================

  typedef enum {
    WRITE,
    READ
  } State;

  State curr_state;
  State next_state;

  always_comb begin

    case (curr_state)

      WRITE: begin
        o_ready_deq = 1;
        o_ready_enq = 1;
        o_ready_rep = 1;
        if ((i_read && !i_wrt) || (i_read && i_wrt)) begin
          next_state = READ;
        end else begin
          next_state = WRITE;
        end
      end

      READ: begin
        o_ready_deq = 1;
        o_ready_enq = 0;
        o_ready_rep = 0;
        next_state  = WRITE;
      end

      default: begin
        o_ready_deq = 0;
        o_ready_enq = 0;
        o_ready_rep = 0;
        next_state  = WRITE;
      end

    endcase

  end

  always_ff @(posedge CLK) begin

    if (!RSTn) begin

      curr_size <= '0;
      curr_state <= WRITE;

      inQueueValid <= '0;
      outQueueValid <= '0;

      for (i = 0; i < QUEUE_SIZE; i += 1) begin
        inQueue[i]  <= '1;
        outQueue[i] <= '1;
      end

    end else begin
      curr_size     <= next_size;
      curr_state    <= next_state;
      inQueue       <= nextInQueue;
      inQueueValid  <= nextInQueueValid;
      outQueue      <= nextOutQueue;
      outQueueValid <= nextOutQueueValid;
    end

  end

endmodule
