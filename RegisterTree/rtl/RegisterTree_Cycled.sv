`default_nettype none

module RegisterTree_Cycled #(
    parameter bit ENQ_ENA = 1,    // Define if user would like to enable enqueue
    parameter int QUEUE_SIZE = 15,
    parameter int DATA_WIDTH = 16
) (
    // Synchronous Control
    input var logic i_CLK,
    input var logic i_RSTn,
    // Inputs
    input var logic i_wrt,
    input var logic i_read,
    input var logic [DATA_WIDTH-1:0] i_data,
    // Outputs
    output var logic o_full,
    output var logic o_empty,
    output var logic [DATA_WIDTH-1:0] o_data
);

  //----------------------------------------------------------------------
  // Local Parameters
  //----------------------------------------------------------------------
  localparam int TREE_DEPTH = $clog2(QUEUE_SIZE);  // depth of the tree
  localparam int NODES_NEEDED = (1 << TREE_DEPTH) - 1;  // number of nodes needed to initialize

  //----------------------------------------------------------------------
  // Internal Registers and Wires
  //----------------------------------------------------------------------
  // Storage elements - Add public modifier for testbench access
  logic [DATA_WIDTH-1:0] queue[NODES_NEEDED];
  logic [DATA_WIDTH-1:0] reset_queue[NODES_NEEDED];
  
  // Size counter - Add public modifier for testbench access
  logic [$clog2(NODES_NEEDED)-1:0] size;
  logic empty, full;

  // Control signals
  logic enqueue, dequeue, replace, even_cycle_flag, next_even_cycle_flag;
  
  // Results of each operation - calculated in parallel - Add public modifier for testbench access
  logic [DATA_WIDTH-1:0] swap_result[NODES_NEEDED];
  logic [DATA_WIDTH-1:0] enq_result[NODES_NEEDED];
  logic [DATA_WIDTH-1:0] deq_result[NODES_NEEDED];
  logic [DATA_WIDTH-1:0] rep_result[NODES_NEEDED];
  
  // Size after each operation - Add public modifier for testbench access
  logic [$clog2(NODES_NEEDED)-1:0] size_after_swap;
  logic [$clog2(NODES_NEEDED)-1:0] size_after_enq;
  logic [$clog2(NODES_NEEDED)-1:0] size_after_deq;
  logic [$clog2(NODES_NEEDED)-1:0] size_after_rep;

  //----------------------------------------------------------------------
  // Initialize reset_queue to zeros
  //----------------------------------------------------------------------
  generate
    for (genvar i = 0; i < NODES_NEEDED; i++) begin : l_gen_reset_queue
      assign reset_queue[i] = '0;
    end
  endgenerate

  //----------------------------------------------------------------------
  // Signals assignments
  //----------------------------------------------------------------------
  // Control signal assignment
  assign enqueue = (ENQ_ENA && i_wrt && !i_read) ? 1'b1 : 1'b0; // Only enable enqueue if ENQ_ENA is high
  assign dequeue = !i_wrt && i_read ? 1'b1 : 1'b0;
  assign replace = i_wrt && i_read ? 1'b1 : 1'b0;
  // Size counter signals
  assign empty = (size <= 0) ? 1'b1 : 1'b0;
  assign full = (size >= QUEUE_SIZE) ? 1'b1 : 1'b0;
  assign o_full = full;
  assign o_empty = empty;
  assign o_data = queue[0];

  //----------------------------------------------------------------------
  // Compare and Swap operation
  //----------------------------------------------------------------------
  always_comb begin : prepare_swap_result
    case (even_cycle_flag)
      1'b1 : begin // Even cycle
        swap_result = queue; // Initialize swap_result with current queue
        for (int lvl = 0; lvl < TREE_DEPTH; lvl++) begin // Iterate through levels
          if (lvl % 2 == 0 && lvl < TREE_DEPTH - 1) begin // Process only even levels (0, 2, 4...)
            for (int i = (1 << lvl) - 1; i < (1 << (lvl + 1)) - 1; i++) begin // Iterate through nodes at this level

              logic [DATA_WIDTH-1:0] new_parent, new_left, new_right;
              
              // Default assignments - keep original values
              new_parent = queue[i];
              new_left = (2*i+1 < NODES_NEEDED) ? queue[2*i+1] : '0;
              new_right = (2*i+2 < NODES_NEEDED) ? queue[2*i+2] : '0;
              
              if ((2*i+1 < NODES_NEEDED) && (2*i+2 < NODES_NEEDED)) begin // If both children exist
                if (queue[2*i+1] > queue[2*i+2]) begin // Left child is greater than right child
                  if (queue[i] < queue[2*i+1]) begin // Parent is less than left child - swap
                    new_parent = queue[2*i+1];
                    new_left = queue[i];
                  end else begin // Parent is greater than or equal to left child
                    // Do nothing
                  end
                end else begin // Right child is greater than or equal to left child
                  if (queue[i] < queue[2*i+2]) begin // Parent is less than right child - swap
                    new_parent = queue[2*i+2];
                    new_right = queue[i];
                  end else begin // Parent is greater than or equal to right child
                    // Do nothing
                  end
                end
              end else begin // No children exist
                // Do nothing
              end
              
              // Update result with new values
              swap_result[i] = new_parent;
              if (2*i+1 < NODES_NEEDED) begin 
                swap_result[2*i+1] = new_left;
              end else begin
                // Do nothing
              end
              if (2*i+2 < NODES_NEEDED) begin
                swap_result[2*i+2] = new_right;
              end else begin
                // Do nothing
              end
            end
          end else begin
            // Do nothing for odd levels
          end
        end
        
        // Set flag for running odd cycle
        next_even_cycle_flag = 1'b0;
      end

      1'b0 : begin // Odd cycle
        swap_result = queue; // Initialize swap_result with current queue
        for (int lvl = 0; lvl < TREE_DEPTH; lvl++) begin // Iterate through levels
          if (lvl % 2 == 1 && lvl < TREE_DEPTH - 2) begin // Process only odd levels (1, 3, 5...)
            for (int i = (1 << lvl) - 1; i < (1 << (lvl + 1)) - 1; i++) begin // Iterate through nodes at this level

              logic [DATA_WIDTH-1:0] new_parent, new_left, new_right;
              
              new_parent = queue[i];
              new_left = (2*i+1 < NODES_NEEDED) ? queue[2*i+1] : '0;
              new_right = (2*i+2 < NODES_NEEDED) ? queue[2*i+2] : '0;
              
              if ((2*i+1 < NODES_NEEDED) && (2*i+2 < NODES_NEEDED)) begin // If both children exist
                if (queue[2*i+1] > queue[2*i+2]) begin // Left child is greater than right child
                  if (queue[i] < queue[2*i+1]) begin // Parent is less than left child - swap
                    new_parent = queue[2*i+1];
                    new_left = queue[i];
                  end else begin // Parent is greater than or equal to left child
                    // Do nothing
                  end
                end else begin // Right child is greater than or equal to left child
                  if (queue[i] < queue[2*i+2]) begin // Parent is less than right child
                    new_parent = queue[2*i+2];
                    new_right = queue[i];
                  end else begin // Parent is greater than or equal to right child - no swap needed
                    // Do nothing
                  end
                end
              end else begin // No children exist - heap property is maintained
              end
              
              // Update result with new values
              swap_result[i] = new_parent;
              if (2*i+1 < NODES_NEEDED) begin
                swap_result[2*i+1] = new_left;
              end else begin
                // Do nothing
              end
              if (2*i+2 < NODES_NEEDED) begin
                swap_result[2*i+2] = new_right;
              end else begin
                // Do nothing
              end
            end
          end else begin
            // Do nothing for even levels
          end
        end
        
        // Set flag for next cycle
        next_even_cycle_flag = 1'b1;
      end

      default : begin 
        swap_result = queue;
        next_even_cycle_flag = 1'b1;
      end
    endcase
    
    size_after_swap = size;
  end

  //----------------------------------------------------------------------
  // Enqueue operation
  //----------------------------------------------------------------------
  always_comb begin : prepare_enq_result
    // Find first empty slot
    logic [$clog2(NODES_NEEDED)-1:0] found_empty_idx;
    found_empty_idx = NODES_NEEDED;
    
    for (int i = NODES_NEEDED-1; i >= 0; i--) begin
      if (queue[i] == 0) begin
        found_empty_idx = (i < found_empty_idx) ? i : found_empty_idx;
      end else begin
        found_empty_idx = found_empty_idx;
      end
    end
    
    // Create enqueue result
    enq_result = queue;
    
    if (found_empty_idx < NODES_NEEDED) begin
      enq_result[found_empty_idx] = i_data;
    end else begin
      // Do nothing
    end
    
    // Update size after enqueue
    size_after_enq = (!full) ? size + 1 : size;
  end

  //----------------------------------------------------------------------
  // Dequeue operation
  //----------------------------------------------------------------------
  always_comb begin : prepare_deq_result
    // Create dequeue result - remove root
    deq_result = queue;
    deq_result[0] = '0;
    
    // Update size after dequeue
    size_after_deq = (!empty) ? size - 1 : size;
  end

  //----------------------------------------------------------------------
  // Replace operation
  //----------------------------------------------------------------------
  always_comb begin : prepare_rep_result
    // Create replace result - replace root
    rep_result = queue;
    rep_result[0] = i_data;
    
    // Update size after replace
    size_after_rep = (size == 0 && i_data != '0) ? size + 1 : size;
  end

  //----------------------------------------------------------------------
  // Sequential logic - update registers
  //----------------------------------------------------------------------
  always_ff @(posedge i_CLK or negedge i_RSTn) begin : update_registers
    if (!i_RSTn) begin
      // Reset condition
      queue <= reset_queue;
      size <= 0;
      even_cycle_flag <= 1'b1;
    end else begin
      case ({enqueue, dequeue, replace})
        3'b100 : begin // Enqueue operation
          queue <= enq_result;
          size <= size_after_enq;
          even_cycle_flag <= 1'b1;
        end
        
        3'b010 : begin // Dequeue operation
          queue <= deq_result;
          size <= size_after_deq;
          even_cycle_flag <= 1'b1;
        end
        
        3'b001 : begin // Replace operation
          queue <= rep_result;
          size <= size_after_rep;
          even_cycle_flag <= 1'b1;
        end
        
        default : begin // Compare and swap for heap maintenance
          queue <= swap_result;
          size <= size_after_swap;
          even_cycle_flag <= next_even_cycle_flag;
        end
      endcase
    end
  end

endmodule
