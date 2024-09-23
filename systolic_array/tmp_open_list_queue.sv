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
  logic [ DATA_WIDTH-1:0] IB                                          [0:QUEUE_SIZE-1];
  logic                   IB_valid                                    [0:QUEUE_SIZE-1];
  logic [ DATA_WIDTH-1:0] OB                                          [0:QUEUE_SIZE-1];
  logic                   OB_valid                                    [0:QUEUE_SIZE-1];
  // Next values for Input Buffer (IB) and Output Buffer (OB)
  logic [ DATA_WIDTH-1:0] next_IB                                     [0:QUEUE_SIZE-1];
  logic                   next_IB_valid                               [0:QUEUE_SIZE-1];
  logic [ DATA_WIDTH-1:0] next_OB                                     [0:QUEUE_SIZE-1];
  logic                   next_OB_valid                               [0:QUEUE_SIZE-1];
  logic [INDEX_WIDTH+1:0] next_size;
  // Temporary variable for swapping
  logic [ DATA_WIDTH-1:0] temp_IB;
  logic                   temp_IB_valid;
  logic [ DATA_WIDTH-1:0] temp_OB;

  // Control signals
  logic [INDEX_WIDTH+1:0] size;  // Total number of nodes in the queue
  logic                   full;
  logic                   empty;

  // Output assignments
  assign o_full   = full;
  assign full     = (size >= 2 * QUEUE_SIZE);  // Adjust based on total capacity of IB and OB
  assign o_empty  = empty;
  assign empty    = (size == 0);
  assign o_valid  = OB_valid[0];
  assign o_node_f = OB[0];

  // Sequential logic
  always_ff @(posedge CLK or negedge RSTn) begin
    if (!RSTn) begin  // Reset
      size <= 0;
      for (int i = 0; i < QUEUE_SIZE; i++) begin
        IB[i]       <= '0;
        IB_valid[i] <= 1'b0;
        OB[i]       <= '0;
        OB_valid[i] <= 1'b0;
      end
    end else begin  // Normal operation: update registers with next_* signals
      size     <= next_size;
      IB       <= next_IB;
      IB_valid <= next_IB_valid;
      OB       <= next_OB;
      OB_valid <= next_OB_valid;
    end
  end

  // Combinational logic
  always_comb begin
    // Defaults
    next_IB = IB;
    next_IB_valid = IB_valid;
    next_OB = OB;
    next_OB_valid = OB_valid;
    next_size = size;
    temp_IB = '0;
    temp_IB_valid = 1'b0;
    temp_OB = '0;

    // Enqueue operation
    if (i_wrt && i_valid) begin
      next_IB[0]       = i_node_f;
      next_IB_valid[0] = 1'b1;
      // next_size        = size + 1;  // Update size
    end

    // Dequeue operation
    if (i_read) begin
      // Remove the head of OB, creating a bubble at OB[0]
      next_OB[0]       = '0;
      next_OB_valid[0] = 1'b0;
      // next_size        = size - 1;  // Update size

      // Handle the bubble
      if (next_OB_valid[1] && next_IB_valid[0]) begin  // IB[0] and OB[1] are valid
        if (next_IB[0] < next_OB[1]) begin  // Compare IB[0] and OB[1], if IB[0] has lower 'f' value
          // Swap IB[0] to OB[0]
          next_OB[0]       = next_IB[0];
          next_OB_valid[0] = 1'b1;
          next_IB[0]       = '0;
          next_IB_valid[0] = 1'b0;
        end else begin  // OB[1] has lower or equal 'f' value
          // Move OB[1] to OB[0]
          next_OB[0]       = next_OB[1];
          next_OB_valid[0] = 1'b1;
          // Shift the bubble to OB[1]
          next_OB[1]       = '0;
          next_OB_valid[1] = 1'b0;
        end
      end else if (next_IB_valid[0] && !next_OB_valid[1]) begin  // OB[1] is not valid; IB[0] is valid; move IB[0] to OB[0]
        next_OB[0]       = next_IB[0];
        next_OB_valid[0] = 1'b1;
        next_IB[0]       = '0;
        next_IB_valid[0] = 1'b0;
      end else if (next_OB_valid[1] && !next_IB_valid[0]) begin  // OB[1] is valid; IB[0] is not valid; move OB[1] to OB[0]
        next_OB[0]       = next_OB[1];
        next_OB_valid[0] = 1'b1;
        next_OB[1]       = '0;
        next_OB_valid[1] = 1'b0;
      end
    end

    // Size update logic
    if (i_wrt && i_valid && i_read) begin // If enqueue and dequeue at the same time, the size does not change
      next_size = size;
    end else if (i_wrt && !i_read) begin  // If only enqueue, the size increases
      next_size = size + 1;
    end else if (!i_wrt && i_read) begin  // If only dequeue, the size decreases
      next_size = size - 1;
    end

    // OB sorting logic
    for (int i = 0; i < QUEUE_SIZE; i++) begin
      if (next_OB_valid[i]) begin  // OB[i] is valid
        if (i < QUEUE_SIZE - 1) begin  // If not the last element in OB
          if (next_OB_valid[i+1]) begin  // OB[i+1] is valid
            if (next_IB_valid[i+1]) begin  // IB[i+1] is valid
              // Compare IB[i+1] and OB[i]
              if (next_IB[i+1] < next_OB[i]) begin  // IB[i+1] < OB[i]
                // Swap IB[i+1] and OB[i]
                temp_OB = next_OB[i];
                next_OB[i] = next_IB[i+1];
                next_OB_valid[i] = 1'b1;
                next_IB[i+1] = temp_OB;
                next_IB_valid[i+1] = 1'b1;
              end
            end else begin  // IB[i+1] is not valid
              // Compare OB[i] and OB[i+1]
              if (next_OB[i+1] < next_OB[i]) begin  // OB[i+1] < OB[i]
                // Swap OB[i] and OB[i+1]
                temp_OB = next_OB[i];
                next_OB[i] = next_OB[i+1];
                next_OB[i+1] = temp_OB;
                next_OB_valid[i] = 1'b1;
                next_OB_valid[i+1] = 1'b1;
              end
            end
          end
        end
      end else begin  // OB[i] is not valid
        if (i < QUEUE_SIZE - 1) begin  // If not the last element in OB
          if (next_OB_valid[i+1]) begin  // OB[i+1] is valid
            // Move OB[i+1] to OB[i]
            next_OB[i] = next_OB[i+1];
            next_OB_valid[i] = 1'b1;
            next_OB[i+1] = '0;
            next_OB_valid[i+1] = 1'b0;
          end
        end
      end
    end

    // IB sorting logic
    for (int i = 0; i < QUEUE_SIZE; i++) begin  // Iterate through each element in IB
      if (next_IB_valid[i]) begin  // IB[i] is valid
        if (i < QUEUE_SIZE - 1) begin  // If not the last element in IB
          if (next_OB_valid[i] && next_OB_valid[i+1]) begin  // OB[i] and OB[i+1] are valid
            // Case 1: Compare IB[i] with OB[i] and OB[i+1]
            if (next_IB[i] < next_OB[i]) begin  // IB[i] < OB[i]
              // Swap IB[i] and OB[i]
              temp_OB          = next_OB[i];
              next_OB[i]       = next_IB[i];
              next_OB_valid[i] = 1'b1;
              next_IB[i]       = temp_OB;
              next_IB_valid[i] = 1'b1;
            end else if (next_IB[i] < next_OB[i+1]) begin  // IB[i] < OB[i+1]
              // Swap IB[i] and OB[i+1]
              temp_OB            = next_OB[i+1];
              next_OB[i+1]       = next_IB[i];
              next_OB_valid[i+1] = 1'b1;
              next_IB[i]         = temp_OB;
              next_IB_valid[i]   = 1'b1;
            end
          end else if (next_OB_valid[i] && !next_OB_valid[i+1]) begin  // OB[i] is valid and OB[i+1] is not valid
            if (next_IB[i] < next_OB[i]) begin  // IB[i] < OB[i]
              // Swap IB[i] and OB[i]
              temp_OB          = next_OB[i];
              next_OB[i]       = next_IB[i];
              next_OB_valid[i] = 1'b1;
              next_IB[i]       = temp_OB;
              next_IB_valid[i] = 1'b1;
            end else begin
              // Move IB[i] to OB[i+1]
              next_OB[i+1]       = next_IB[i];
              next_OB_valid[i+1] = 1'b1;
              next_IB[i]         = '0;
              next_IB_valid[i]   = 1'b0;
            end
          end else if (!next_OB_valid[i] && next_OB_valid[i+1]) begin  // OB[i] is not valid and OB[i+1] is valid
            // Move IB[i] to OB[i]
            next_OB[i]       = next_IB[i];
            next_OB_valid[i] = 1'b1;
            next_IB[i]       = '0;
            next_IB_valid[i] = 1'b0;
          end else if (!next_OB_valid[i] && !next_OB_valid[i+1]) begin  // OB[i] and OB[i+1] are not valid
            // Move IB[i] to OB[i]
            next_OB[i]       = next_IB[i];
            next_OB_valid[i] = 1'b1;
            next_IB[i]       = '0;
            next_IB_valid[i] = 1'b0;
          end
          // IB propagation logic
          if (next_IB_valid[i+1]) begin  // IB[i+1] is valid
            if (next_IB[i] > next_IB[i+1]) begin  // IB[i] > IB[i+1]
              // Swap IB[i] and IB[i+1]
              temp_IB = next_IB[i];
              temp_IB_valid = next_IB_valid[i];
              next_IB[i] = next_IB[i+1];
              next_IB_valid[i] = next_IB_valid[i+1];
              next_IB[i+1] = temp_IB;
              next_IB_valid[i+1] = temp_IB_valid;
            end
          end else begin  // IB[i+1] is not valid
            // move IB[i] to IB[i+1]
            next_IB[i+1]       = next_IB[i];
            next_IB_valid[i+1] = next_IB_valid[i];
            next_IB[i]         = '0;
            next_IB_valid[i]   = 1'b0;
          end
        end else begin  // Last element in IB
          if (next_OB_valid[i]) begin  // OB[i] is valid
            // compare IB[i] and OB[i]
            if (next_IB[i] < next_OB[i]) begin  // IB[i] < OB[i]
              // Swap IB[i] and OB[i]
              temp_OB          = next_OB[i];
              next_OB[i]       = next_IB[i];
              next_OB_valid[i] = 1'b1;
              next_IB[i]       = temp_OB;
              next_IB_valid[i] = 1'b1;
            end
          end else begin  // OB [i] is not valid
            // Move IB[i] to OB[i]
            next_OB[i]       = next_IB[i];
            next_OB_valid[i] = 1'b1;
            next_IB[i]       = '0;
            next_IB_valid[i] = 1'b0;
          end
        end
      end
    end
  end

endmodule
