/*
    This module implements a priority queue using two buffers.
    It is used to store the open list in the A* search algorithm.
    This architecture is proposed in the paper published in 2020, 
    written by Zhou etc.
    P.S. This is a Min Queue, which means the smallest element is always at the head of the queue.
*/
module open_list_queue #(
    parameter QUEUE_SIZE = 4,
    parameter DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst_n, // Added reset signal
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
  } node_t;

  node_t [QUEUE_SIZE-2:0] ib, ib_next;
  node_t [QUEUE_SIZE-1:0] ob, ob_next;
  node_t temp_node = '0;

  logic [QUEUE_SIZE-2:0] ib_valid;
  logic [QUEUE_SIZE-1:0] ob_valid;

  // Main logic
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      // Initialization of two buffers to mimic the example in the paper
      ib[0].data <= 32'd1;
      ib[0].f_value <= 32'd3;
      ib[1].data <= 32'd2;
      ib[1].f_value <= '1;
      ib[2].data <= 32'd3;
      ib[2].f_value <= '1;

      ob[0].data <= 32'd4;
      ob[0].f_value <= 32'd2;
      ob[1].data <= 32'd5;
      ob[1].f_value <= 32'd5;
      ob[2].data <= 32'd6;
      ob[2].f_value <= 32'd7;
      ob[3].data <= 32'd7;
      ob[3].f_value <= '1;
    end else begin
      ib <= ib_next;
      ob <= ob_next;
    end
  end

  always_comb begin

    // ib_next = ib;
    // ob_next = ob;

    if (insert && ib[0].f_value == '1) begin
      ib_next[0] = {in_data, in_f_value};
    end

    if (pop && ob[0].f_value != '1) begin
      if (ib[0].f_value < ob[1].f_value) begin
        ob_next[0] = ib[0];
        ib_next[0].data = '0;
        ib_next[0].f_value = '1;
      end else begin
        ob_next[0] = ob[1];
        ob_next[1].data = '0;
        ob_next[1].f_value = '1;
      end
    end

    // IB[i] sorting logic 
    for (int i = 0; i <= QUEUE_SIZE - 2; i++) begin
      if (ib[i].f_value < ob[i].f_value) begin
        ob_next[i] = ib[i];
        ib_next[i].data = '0;
        ib_next[i].f_value = '1;
      end else begin
        if (ib[i].f_value < ob[i+1].f_value) begin
          ob_next[i+1] = ib[i];
          ib_next[i+1] = ob[i+1];
          ib_next[i].data = '0;
          ib_next[i].f_value = '1;
        end else begin
          ib_next[i+1] = ib[i];
          ib_next[i].data = '0;
          ib_next[i].f_value = '1;
        end
      end
    end

    // OB[i] sorting logic
    for (int i = 0; i <= QUEUE_SIZE - 2; i++) begin
      if (ob[i+1].f_value < ob[i].f_value) begin
        ob_next[i+1] = ob[i];
        ob_next[i] = ob[i+1];
      end
    end

    // identify for validity
    for (int i = 0; i < QUEUE_SIZE; i++) begin
      if (ib[i].f_value == '1) begin
        ib_valid[i] = 0;
      end else begin
        ib_valid[i] = 1;
      end
      if (ob[i].f_value == '1) begin
        ob_valid[i] = 0;
      end else begin
        ob_valid[i] = 1;
      end
    end
  end 

  assign empty = ob_valid == {QUEUE_SIZE{1'b0}};
  assign full = ib_valid == {QUEUE_SIZE-1{1'b1}};
  assign out_data = ob[0].data;
  assign out_f_value = ob[0].f_value;

endmodule
