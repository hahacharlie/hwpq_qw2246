module tmp_open_list_queue #(
    parameter QUEUE_SIZE = 4,  // Size of the buffers (number of positions)
    parameter DATA_WIDTH = 32  // Width of the node data (evaluation function value 'f')
) (
    input logic CLK,
    input logic RSTn,

    // Input control signals
    input logic                  i_wrt,    // Enqueue signal
    input logic                  i_read,   // Dequeue signal
    input logic                  i_valid,  // Input data valid
    input logic [DATA_WIDTH-1:0] i_node_f, // Node data input

    // Output control signals
    output logic                  o_full,   // Queue is full
    output logic                  o_empty,  // Queue is empty
    output logic                  o_valid,  // Output data valid
    output logic [DATA_WIDTH-1:0] o_node_f  // Node data output
);

  // Constants and indices
  localparam INDEX_WIDTH = $clog2(QUEUE_SIZE);

  // Input Buffer (IB) and Output Buffer (OB)
  logic [DATA_WIDTH-1:0] IB                                          [0:QUEUE_SIZE-1];
  logic                  IB_valid                                    [0:QUEUE_SIZE-1];
  logic [DATA_WIDTH-1:0] OB                                          [0:QUEUE_SIZE-1];
  logic                  OB_valid                                    [0:QUEUE_SIZE-1];
  // Copy current values to avoid unintended overwrites
  // This is useful when multiple conditions might modify the same variables
  logic [DATA_WIDTH-1:0] next_IB                                     [0:QUEUE_SIZE-1];
  logic                  next_IB_valid                               [0:QUEUE_SIZE-1];
  logic [DATA_WIDTH-1:0] next_OB                                     [0:QUEUE_SIZE-1];
  logic                  next_OB_valid                               [0:QUEUE_SIZE-1];
  logic [ INDEX_WIDTH:0] next_size;

  // Control signals
  logic [ INDEX_WIDTH:0] size;  // Total number of nodes in the queue
  logic                  full;
  logic                  empty;

  // Output assignments
  assign o_full   = full;
  assign full     = (size >= QUEUE_SIZE);  // Adjust based on total capacity of IB and OB
  assign o_empty  = empty;
  assign empty    = (size == 0);
  assign o_valid  = OB_valid[0];
  assign o_node_f = OB[0];

  // State machine
  typedef enum logic [1:0] {
    IDLE,
    ENQUEUE,
    DEQUEUE,
    SORT
  } state_t;
  state_t current_state, next_state;

  // Sequential logic for state machine
  always_ff @(posedge CLK or negedge RSTn) begin
    if (!RSTn) begin
      current_state <= IDLE;
    end else begin
      current_state <= next_state;
    end
  end

  // Combinational logic for state transitions
  always_comb begin
    next_state = current_state;
    case (current_state)
      IDLE: begin
        if (i_wrt && i_valid && !full) begin
          next_state = ENQUEUE;
        end else if (i_read && !empty) begin
          next_state = DEQUEUE;
        end else begin
          next_state = SORT;
        end
      end
      ENQUEUE: begin
        if (i_read && !empty) begin
          next_state = DEQUEUE;
        end else begin
          next_state = SORT;
        end
      end
      DEQUEUE: begin
        if (i_wrt && i_valid && !full) begin
          next_state = ENQUEUE;
        end else begin
          next_state = SORT;
        end
      end
      SORT: begin
        if (i_wrt && i_valid && !full) begin
          next_state = ENQUEUE;
        end else if (i_read && !empty) begin
          next_state = DEQUEUE;
        end else begin
          next_state = IDLE;
        end
      end
    endcase
  end

  // Sequential logic for state machine
  always_ff @(posedge CLK or negedge RSTn) begin
    case (current_state)
      IDLE: begin
        size <= 0;
        for (int i = 0; i < QUEUE_SIZE; i++) begin
          IB[i]       <= '0;
          IB_valid[i] <= 1'b0;
          OB[i]       <= '0;
          OB_valid[i] <= 1'b0;
        end
      end
      ENQUEUE: begin
        // Update the actual registers with non-blocking assignments
        //   size <= next_size;
        // for (int i = 0; i < QUEUE_SIZE; i++) begin
        //   IB[i]       <= next_IB[i];
        //   IB_valid[i] <= next_IB_valid[i];
        //   OB[i]       <= next_OB[i];
        //   OB_valid[i] <= next_OB_valid[i];
      end
      DEQUEUE: begin
      end
      SORT: begin
      end
    endcase
  end

  always_latch begin
    // Initialize with current values
    //! This is latching up the old values of the buffers and control signals
    next_size = size;
    for (int i = 0; i < QUEUE_SIZE; i++) begin
      next_IB[i]       = IB[i];
      next_IB_valid[i] = IB_valid[i];
      next_OB[i]       = OB[i];
      next_OB_valid[i] = OB_valid[i];
    end

    // Enqueue operation: Insert new node into IB_0
    if (i_wrt && i_valid && !full) begin
      // Shift IB elements to make room at IB_0
      for (int i = QUEUE_SIZE - 1; i > 0; i--) begin
        next_IB[i]       = next_IB[i-1];
        next_IB_valid[i] = next_IB_valid[i-1];
      end
      // Insert new node into IB_0
      next_IB[0]       = i_node_f;
      next_IB_valid[0] = 1'b1;

      // Increment size
      next_size        = next_size + 1;
    end

    // Dequeue operation and bubble handling combined
    if (i_read && !empty) begin
      // Invalidate OB[0]
      next_OB[0]       = '0;
      next_OB_valid[0] = 1'b0;

      // Decrement size
      next_size        = next_size - 1;

      // Bubble handling after dequeue
      if (!next_OB_valid[0]) begin  // if there is a bubble at the head of the OB
        if (next_IB_valid[0] && next_OB_valid[1]) begin  // if there is a valid element at IB[0] and OB[1]
          // Compare IB[0] and OB[1]
          if (next_IB[0] < next_OB[1]) begin  // if IB[0] is smaller than OB[1]
            // Move IB[0] to OB[0]
            next_OB[0]       = next_IB[0];
            next_OB_valid[0] = 1'b1;
          end else begin  // if IB[0] is not smaller than OB[1]
            // Move OB[1] to OB[0]
            next_OB[0]       = next_OB[1];
            next_OB_valid[0] = 1'b1;
          end
        end
      end
    end else if (!next_OB_valid[0]) begin  // if there is a bubble at the head of the OB but no dequeue operation was performed
      // Bubble handling when there's no dequeue
      // Existing bubble handling logic goes here
      // ...
    end

    // Sorting process: Compare and swap between IB and OB
    // Process for each position in the buffers
    for (int i = 0; i < QUEUE_SIZE; i++) begin
      if (next_IB_valid[i]) begin  // if IB_i is valid
        if ((i < QUEUE_SIZE - 1) && next_OB_valid[i+1]) begin // If not the last element of IB and OB_i+1 is valid
          // Case 1: Compare IB_i with OB_i+1
          if (next_IB[i] < next_OB[i+1]) begin  // If IB_i is smaller than OB_i+1
            // Swap IB_i and OB_i+1
            logic [DATA_WIDTH-1:0] temp_OB;
            temp_OB            = next_OB[i+1];
            next_OB[i+1]       = next_IB[i];
            next_OB_valid[i+1] = 1'b1;
            next_IB[i]         = temp_OB;
            next_IB_valid[i]   = 1'b1;
          end else begin  // if IB_i is not smaller than OB_i+1
            // Case 2: Compare IB_i with OB_i
            if (next_OB_valid[i]) begin  // if OB_i is valid
              if (next_IB[i] < next_OB[i]) begin  // if IB_i is smaller than OB_i
                // Swap IB_i and OB_i
                logic [DATA_WIDTH-1:0] temp_OB;
                temp_OB          = next_OB[i];
                next_OB[i]       = next_IB[i];
                next_OB_valid[i] = 1'b1;
                next_IB[i]       = temp_OB;
                next_IB_valid[i] = 1'b1;
              end
            end else begin  // if OB_i is not valid
              // Move IB_i to OB_i
              next_OB[i]       = next_IB[i];
              next_OB_valid[i] = 1'b1;
              // Invalidate IB_i
              next_IB[i]       = '0;
              next_IB_valid[i] = 1'b0;
            end
          end
        end else begin  // If the OB_i+1 is not valid
          // Case 2: No valid OB_i+1, first compare with OB_i, if IB_i is smaller, swap IB_i and OB_i, if not, move IB_i to OB_i+1
          if (i < QUEUE_SIZE - 1) begin
            if (next_OB_valid[i]) begin
              if (next_IB[i] < next_OB[i]) begin  // If IB_i is smaller than OB_i
                // Swap IB_i and OB_i
                logic [DATA_WIDTH-1:0] temp_OB;
                temp_OB          = next_OB[i];
                next_OB[i]       = next_IB[i];
                next_OB_valid[i] = 1'b1;
                next_IB[i]       = temp_OB;
                next_IB_valid[i] = 1'b1;
              end else begin  // If IB_i is not smaller than OB_i
                // Move IB_i to OB_i+1
                next_OB[i+1]       = next_IB[i];
                next_OB_valid[i+1] = 1'b1;
              end
            end else begin  // If OB_i is not valid
              // Move IB_i to OB_i
              next_OB[i]       = next_IB[i];
              next_OB_valid[i] = 1'b1;
            end
          end
          // Invalidate IB_i
          next_IB[i]       = '0;
          next_IB_valid[i] = 1'b0;
        end
      end
    end

    // // Handle bubble when OB_0 is empty (due to dequeue)
    // if (!next_OB_valid[0]) begin  // If OB_0 is empty
    //   if (next_IB_valid[0]) begin  // If IB_0 is valid
    //     // Compare IB_0 with OB_1
    //     if (next_OB_valid[1]) begin  // If OB_1 is valid
    //       if (next_IB[0] < next_OB[1]) begin  // If IB_0 is smaller than OB_1
    //         // Move IB_0 to OB_0
    //         next_OB[0]       = next_IB[0];
    //         next_OB_valid[0] = 1'b1;

    //         // Shift IB elements
    //         for (i = 0; i < QUEUE_SIZE - 1; i++) begin
    //           next_IB[i]       = next_IB[i+1];
    //           next_IB_valid[i] = next_IB_valid[i+1];
    //         end
    //         // Invalidate last IB position
    //         next_IB[QUEUE_SIZE-1]       = '0;
    //         next_IB_valid[QUEUE_SIZE-1] = 1'b0;
    //       end else begin
    //         // Shift OB elements to fill the bubble
    //         for (i = 0; i < QUEUE_SIZE - 1; i++) begin
    //           next_OB[i]       = next_OB[i+1];
    //           next_OB_valid[i] = next_OB_valid[i+1];
    //         end
    //         // Place IB_0 into OB at the last valid position
    //         next_OB[QUEUE_SIZE-1]       = next_IB[0];
    //         next_OB_valid[QUEUE_SIZE-1] = 1'b1;

    //         // Shift IB elements
    //         for (i = 0; i < QUEUE_SIZE - 1; i++) begin
    //           next_IB[i]       = next_IB[i+1];
    //           next_IB_valid[i] = next_IB_valid[i+1];
    //         end
    //         // Invalidate last IB position
    //         next_IB[QUEUE_SIZE-1]       = '0;
    //         next_IB_valid[QUEUE_SIZE-1] = 1'b0;
    //       end
    //     end else begin
    //       // No valid OB_1, move IB_0 to OB_0
    //       next_OB[0]       = next_IB[0];
    //       next_OB_valid[0] = 1'b1;

    //       // Shift IB elements
    //       for (i = 0; i < QUEUE_SIZE - 1; i++) begin
    //         next_IB[i]       = next_IB[i+1];
    //         next_IB_valid[i] = next_IB_valid[i+1];
    //       end
    //       // Invalidate last IB position
    //       next_IB[QUEUE_SIZE-1]       = '0;
    //       next_IB_valid[QUEUE_SIZE-1] = 1'b0;
    //     end
    //   end else if (next_OB_valid[1]) begin
    //     // Shift OB elements to fill the bubble at OB_0
    //     for (i = 0; i < QUEUE_SIZE - 1; i++) begin
    //       next_OB[i]       = next_OB[i+1];
    //       next_OB_valid[i] = next_OB_valid[i+1];
    //     end
    //     // Invalidate last OB position
    //     next_OB[QUEUE_SIZE-1]       = '0;
    //     next_OB_valid[QUEUE_SIZE-1] = 1'b0;
    //   end
    // end
  end

endmodule
