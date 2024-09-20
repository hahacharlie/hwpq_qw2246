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
  // Next values for Input Buffer (IB) and Output Buffer (OB)
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

  typedef enum logic {
    IDLE,
    LOAD
  } state_t;
  state_t current_state, next_state;

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
      current_state <= IDLE;
    end else begin  // Normal operation: update registers with next_* signals
      size          <= next_size;
      IB            <= next_IB;
      IB_valid      <= next_IB_valid;
      OB            <= next_OB;
      OB_valid      <= next_OB_valid;
      current_state <= next_state;
    end
  end

  // Combinational logic
  always_comb begin
    case (current_state)
      IDLE: begin
        next_size = 0;
        for (int i = 0; i < QUEUE_SIZE; i++) begin
          next_IB[i]       = '0;
          next_IB_valid[i] = 1'b0;
          next_OB[i]       = '0;
          next_OB_valid[i] = 1'b0;
        end
        next_state = LOAD;
      end
      LOAD: begin
        // Enqueue operation
        if (i_wrt && i_valid && !full && !IB_valid[0]) begin
          next_IB[0]       = i_node_f;
          next_IB_valid[0] = 1'b1;
        end

        // Dequeue operation
        if (i_read && !empty && OB_valid[0]) begin
          // Remove the head of OB, creating a bubble at OB[0]
          next_OB[0]       = '0;
          next_OB_valid[0] = 1'b0;

          // Handle the bubble
          if (next_IB_valid[0]) begin  // IB[0] is valid
            if (next_OB_valid[1]) begin  // OB[1] is valid
              if (next_IB[0] < next_OB[1]) begin  // Compare IB[0] and OB[1], if IB[0] has lower 'f' value
                // Move it to OB[0]
                next_OB[0]       = next_IB[0];
                next_OB_valid[0] = 1'b1;
                next_IB[0]       = '0;
                next_IB_valid[0] = 1'b0;
              end else begin  // OB[1] has lower or equal 'f' value
                // Move it to OB[0]
                next_OB[0]       = next_OB[1];
                next_OB_valid[0] = 1'b1;
                // Shift the bubble to OB[1]
                next_OB[1]       = '0;
                next_OB_valid[1] = 1'b0;
              end
            end else begin
              // OB[1] is not valid; move IB[0] to OB[0]
              next_OB[0]       = next_IB[0];
              next_OB_valid[0] = 1'b1;
              next_IB[0]       = '0;
              next_IB_valid[0] = 1'b0;
            end
          end else begin  // IB[0] is not valid
            if (next_OB_valid[1]) begin  // OB[1] is valid
              next_OB[0]       = next_OB[1];
              next_OB_valid[0] = 1'b1;
              // Shift the bubble to OB[1]
              next_OB[1]       = '0;
              next_OB_valid[1] = 1'b0;
            end else begin  // OB[1] is not valid
              next_OB[0]       = '0;
              next_OB_valid[0] = 1'b0;
            end
          end
        end

        // Update size
        if ((i_wrt && i_valid && !full) && (i_read && !empty)) begin
          // Both operations happen
          next_size = size;  // Size remains the same
        end else if (i_wrt && i_valid && !full) begin
          next_size = size + 1;
        end else if (i_read && !empty) begin
          next_size = size - 1;
        end

        // Sorting logic
        for (int i = 0; i < QUEUE_SIZE; i++) begin  // Iterate through each element in IB
          if (next_IB_valid[i]) begin  // IB[i] is valid
            if ((i < QUEUE_SIZE - 1) && next_OB_valid[i+1]) begin // If not the last element in IB and OB[i+1] is valid
              // Case 1: Compare IB[i] with OB[i+1]
              if (next_IB[i] < next_OB[i+1]) begin  // IB[i] < OB[i+1]
                // Swap IB[i] and OB[i+1]
                next_OB[i+1]       = next_IB[i];
                next_OB_valid[i+1] = 1'b1;
                next_IB[i]         = next_OB[i+1];
                next_IB_valid[i]   = 1'b1;
              end
              // move IB[i] to IB[i+1]
              next_IB[i+1]       = next_IB[i];
              next_IB_valid[i+1] = 1'b1;
              next_IB[i]         = '0;
              next_IB_valid[i]   = 1'b0;
            end else begin  // OB[i+1] not valid or last element
              if (!next_OB_valid[i+1] && next_OB_valid[i]) begin  // OB[i+1] not valid, but OB[i] is valid
                // Case 2: compare IB[i] and OB[i]
                if (next_IB[i] < next_OB[i]) begin
                  // Swap IB[i] and OB[i]
                  logic [DATA_WIDTH-1:0] temp_OB;
                  temp_OB          = next_OB[i];
                  next_OB[i]       = next_IB[i];
                  next_OB_valid[i] = 1'b1;
                  next_IB[i]       = temp_OB;
                  next_IB_valid[i] = 1'b1;
                end
              end else begin  // last element
                // Move IB[i] to OB[i]
                next_OB[i]       = next_IB[i];
                next_OB_valid[i] = 1'b1;
                next_IB[i]       = '0;
                next_IB_valid[i] = 1'b0;
              end
            end
          end
        end
        next_state = LOAD;
      end
      default: begin
      end
    endcase
  end

endmodule
