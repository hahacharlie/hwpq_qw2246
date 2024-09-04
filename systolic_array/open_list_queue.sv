module open_list_queue #(
    parameter QUEUE_SIZE = 8,
    parameter DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst_n,
    input logic insert,
    input logic pop,
    input logic [DATA_WIDTH-1:0] in_data,
    input logic [DATA_WIDTH-1:0] in_f_value,
    output logic [DATA_WIDTH-1:0] out_data,
    output logic [DATA_WIDTH-1:0] out_f_value,
    output logic empty,
    output logic full
);

  // Define structures for IB and OB
  typedef struct packed {
    logic [DATA_WIDTH-1:0] data;  // this will be the x, y coordinates value of the node
    logic [DATA_WIDTH-1:0] f_value;
    logic valid;
  } node_t;

  node_t ib[QUEUE_SIZE-1:0];
  node_t ob[QUEUE_SIZE-1:0];

  // Internal signals
  logic [QUEUE_SIZE-1:0] ib_valid, ob_valid;
  logic [$clog2(QUEUE_SIZE)-1:0] ib_head, ob_head;

  //Intialization
  initial begin
    ib_valid = 0;
    ob_valid = 0;
    ib_head  = 0;
    ob_head  = 0;
  end

  // Main logic
  //   always_ff @(posedge clk or negedge rst_n) begin
  //     if (!rst_n) begin
  //       // Reset logic
  //       // ... (initialize ib, ob, ib_valid, ob_valid, ib_head, ob_head)
  //     end else begin

  //     end
  //   end

  always_comb begin
    if (insert) begin
      // Insert new node into IB
      // ... (insert logic)
    end

    if (pop) begin
      // Pop node from OB
      ob[ob_head].valid = 0;
      ob_head = (ob_head + 1) % QUEUE_SIZE;

      // Handle bubble in OB0
      if (ib[0].valid) begin
        if (!ob[1].valid || ib[0].f_value < ob[1].f_value) begin
          ob[0] = ib[0];
          ib[0].valid = 0;
        end else begin
          ob[0] = ob[1];
          ob[1].valid = 0;
        end
      end
    end

    // Comparison and swapping logic
    for (int i = 0; i < QUEUE_SIZE - 1; i++) begin
      if (ib[i].valid && (!ob[i+1].valid || ib[i].f_value < ob[i+1].f_value)) begin
        // Swap nodes
        node_t tmp_node;
        tmp_node = ob[i+1];
        ob[i+1] = ib[i];
        ib[i] = tmp_node;
      end
    end
  end

  // Output assignment
  assign out_data = ob[ob_head].data;
  assign out_f_value = ob[ob_head].f_value;
  assign empty = !ob_valid[ob_head];
  assign full = &ib_valid;

endmodule
