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

  // Control signals
  logic [ INDEX_WIDTH:0] size;  // Total number of nodes in the queue
  logic                  full;
  logic                  empty;

  // Output assignments
  assign o_full   = full;
  assign o_empty  = empty;
  assign o_valid  = OB_valid[0];
  assign o_node_f = OB[0];

  integer i;

  // Initializations and sequential logic
  always_ff @(posedge CLK or negedge RSTn) begin
    if (!RSTn) begin
      // Reset buffers and control signals
      size <= 0;
      for (i = 0; i < QUEUE_SIZE; i++) begin
        IB[i]       <= '0;
        IB_valid[i] <= 1'b0;
        OB[i]       <= '0;
        OB_valid[i] <= 1'b0;
      end
    end else begin
      // Copy current values to avoid unintended overwrites
      // This is useful when multiple conditions might modify the same variables
      logic [DATA_WIDTH-1:0] next_IB      [0:QUEUE_SIZE-1];
      logic                  next_IB_valid[0:QUEUE_SIZE-1];
      logic [DATA_WIDTH-1:0] next_OB      [0:QUEUE_SIZE-1];
      logic                  next_OB_valid[0:QUEUE_SIZE-1];
      logic [ INDEX_WIDTH:0] next_size;

      // Initialize with current values
      for (i = 0; i < QUEUE_SIZE; i++) begin
        next_IB[i]       = IB[i];
        next_IB_valid[i] = IB_valid[i];
        next_OB[i]       = OB[i];
        next_OB_valid[i] = OB_valid[i];
      end
      next_size = size;

      // Enqueue operation: Insert new node into IB_0
      if (i_wrt && i_valid && !full) begin
        // Shift IB elements to make room at IB_0
        for (i = QUEUE_SIZE - 1; i > 0; i--) begin
          next_IB[i]       = next_IB[i-1];
          next_IB_valid[i] = next_IB_valid[i-1];
        end
        // Insert new node into IB_0
        next_IB[0]       = i_node_f;
        next_IB_valid[0] = 1'b1;

        // Increment size
        next_size        = next_size + 1;
      end

      // Dequeue operation: Remove node from OB_0
      if (i_read && !empty) begin
        // Shift OB elements to fill the bubble at OB_0
        for (i = 0; i < QUEUE_SIZE - 1; i++) begin
          next_OB[i]       = next_OB[i+1];
          next_OB_valid[i] = next_OB_valid[i+1];
        end
        // Invalidate last OB position
        next_OB[QUEUE_SIZE-1]       = '0;
        next_OB_valid[QUEUE_SIZE-1] = 1'b0;

        // Decrement size
        next_size                   = next_size - 1;
      end

      // Sorting process: Compare and swap between IB and OB
      // Process for each position in the buffers
      for (i = 0; i < QUEUE_SIZE; i++) begin
        // Only proceed if IB position is valid
        if (next_IB_valid[i]) begin
          // Case 1: Compare IB_i with OB_i+1
          if ((i + 1 < QUEUE_SIZE) && next_OB_valid[i+1]) begin
            if (next_IB[i] < next_OB[i+1]) begin
              // Swap IB_i and OB_i+1
              logic [DATA_WIDTH-1:0] temp_OB;
              temp_OB            = next_OB[i+1];
              next_OB[i+1]       = next_IB[i];
              next_OB_valid[i+1] = 1'b1;
              next_IB[i]         = temp_OB;
              next_IB_valid[i]   = 1'b1;  // Assuming OB_valid[i + 1] was valid
            end else begin
              // Move IB_i to IB_i+1
              if (i + 1 < QUEUE_SIZE) begin
                next_IB[i+1]       = next_IB[i];
                next_IB_valid[i+1] = 1'b1;
              end
              // Invalidate IB_i
              next_IB[i]       = '0;
              next_IB_valid[i] = 1'b0;
            end
          end else begin
            // Case 2: No valid OB_i+1, move IB_i to OB_i+1
            if (i + 1 < QUEUE_SIZE) begin
              next_OB[i+1]       = next_IB[i];
              next_OB_valid[i+1] = 1'b1;
            end
            // Invalidate IB_i
            next_IB[i]       = '0;
            next_IB_valid[i] = 1'b0;
          end
        end
      end

      // Handle bubble when OB_0 is empty (due to dequeue)
      if (!next_OB_valid[0]) begin
        if (next_IB_valid[0]) begin
          // Compare IB_0 with OB_1
          if (next_OB_valid[1]) begin
            if (next_IB[0] < next_OB[1]) begin
              // Move IB_0 to OB_0
              next_OB[0]       = next_IB[0];
              next_OB_valid[0] = 1'b1;

              // Shift IB elements
              for (i = 0; i < QUEUE_SIZE - 1; i++) begin
                next_IB[i]       = next_IB[i+1];
                next_IB_valid[i] = next_IB_valid[i+1];
              end
              // Invalidate last IB position
              next_IB[QUEUE_SIZE-1]       = '0;
              next_IB_valid[QUEUE_SIZE-1] = 1'b0;
            end else begin
              // Shift OB elements to fill the bubble
              for (i = 0; i < QUEUE_SIZE - 1; i++) begin
                next_OB[i]       = next_OB[i+1];
                next_OB_valid[i] = next_OB_valid[i+1];
              end
              // Place IB_0 into OB at the last valid position
              next_OB[QUEUE_SIZE-1]       = next_IB[0];
              next_OB_valid[QUEUE_SIZE-1] = 1'b1;

              // Shift IB elements
              for (i = 0; i < QUEUE_SIZE - 1; i++) begin
                next_IB[i]       = next_IB[i+1];
                next_IB_valid[i] = next_IB_valid[i+1];
              end
              // Invalidate last IB position
              next_IB[QUEUE_SIZE-1]       = '0;
              next_IB_valid[QUEUE_SIZE-1] = 1'b0;
            end
          end else begin
            // No valid OB_1, move IB_0 to OB_0
            next_OB[0]       = next_IB[0];
            next_OB_valid[0] = 1'b1;

            // Shift IB elements
            for (i = 0; i < QUEUE_SIZE - 1; i++) begin
              next_IB[i]       = next_IB[i+1];
              next_IB_valid[i] = next_IB_valid[i+1];
            end
            // Invalidate last IB position
            next_IB[QUEUE_SIZE-1]       = '0;
            next_IB_valid[QUEUE_SIZE-1] = 1'b0;
          end
        end else if (next_OB_valid[1]) begin
          // Shift OB elements to fill the bubble at OB_0
          for (i = 0; i < QUEUE_SIZE - 1; i++) begin
            next_OB[i]       = next_OB[i+1];
            next_OB_valid[i] = next_OB_valid[i+1];
          end
          // Invalidate last OB position
          next_OB[QUEUE_SIZE-1]       = '0;
          next_OB_valid[QUEUE_SIZE-1] = 1'b0;
        end
      end

      // Update the actual registers with non-blocking assignments
      size <= next_size;
      for (i = 0; i < QUEUE_SIZE; i++) begin
        IB[i]       <= next_IB[i];
        IB_valid[i] <= next_IB_valid[i];
        OB[i]       <= next_OB[i];
        OB_valid[i] <= next_OB_valid[i];
      end
    end
  end

  // Update full and empty signals
  always_comb begin
    full  = (size >= 2 * QUEUE_SIZE);  // Adjust based on total capacity of IB and OB
    empty = (size == 0);
  end

endmodule
