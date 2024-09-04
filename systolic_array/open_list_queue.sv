/*
    This module implements a priority queue using two buffers.
    It is used to store the open list in the A* search algorithm.
    This architecture is proposed in the paper published in 2020, 
    written by Zhou etc.
    P.S. This is a Min Queue, which means the smallest element is always at the head of the queue.
*/

/* verilator lint_off ASCRANGE */
/* verilator lint_off ALWCOMBORDER */
/* verilator lint_off UNOPTFLAT */
/* verilator lint_off LATCH */

module open_list_queue #(
    parameter QUEUE_SIZE = 8,
    parameter DATA_WIDTH = 32
) (
    input logic clk,
    // input logic rst_n,
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

  node_t ib[QUEUE_SIZE-2:0];
  node_t ob[QUEUE_SIZE-1:0];
  node_t temp_node;

  logic [0:QUEUE_SIZE-2] ib_valid;
  logic [0:QUEUE_SIZE-1] ob_valid;

  // synthesis translate_off
  //Intialization of two buffers to invalid state indicating that the buffers are empty
  initial begin
    for (int i = 0; i < QUEUE_SIZE; i++) begin
      ib[i].data = 32'hFFFFFFFF;
      ib[i].f_value = 32'hFFFFFFFF;
      ob[i].data = 32'hFFFFFFFF;
      ob[i].f_value = 32'hFFFFFFFF;
    end
  end
  // synthesis translate_on

  // Main logic
  always_ff @(posedge clk) begin
    if (insert && !full) begin
      ib[0].data <= in_data;
      ib[0].f_value <= in_f_value;
    end
    if (pop && !empty) begin
      out_data <= ob[0].data;
      out_f_value <= ob[0].f_value;
      ob[0].data <= 32'hFFFFFFFF;
      ob[0].f_value <= 32'hFFFFFFFF;
    end
  end

  always_comb begin
    if (ob[0].f_value == 32'hFFFFFFFF) begin
      if (ib[0].f_value < ob[1].f_value) begin
        ob[0] = ib[0];
        ib[0].data = 32'hFFFFFFFF;
        ib[0].f_value = 32'hFFFFFFFF;
      end else begin // if the valud f if IB[0] is not smaller than the f value of OB[1], the node in OB[1] will be put in OB[0], and the bubble will shift right
        ob[0] = ob[1];
        ob[1].data = 32'hFFFFFFFF;
        ob[1].f_value = 32'hFFFFFFFF;
      end
    end
    // IB[i] sorting logic 
    for (int i = 0; i <= QUEUE_SIZE - 2; i++) begin
      if (ib[i].f_value < ob[i].f_value) begin
        ob[i] = ib[i];
        ib[i].data = 32'hFFFFFFFF;
        ib[i].f_value = 32'hFFFFFFFF;
      end else begin
        if (ib[i].f_value < ob[i+1].f_value) begin
          temp_node = ob[i+1];
          ob[i+1] = ib[i];
          ib[i+1] = temp_node;
          ib[i].data = 32'hFFFFFFFF;
          ib[i].f_value = 32'hFFFFFFFF;
        end else begin
          ib[i+1] = ib[i];
          ib[i].data = 32'hFFFFFFFF;
          ib[i].f_value = 32'hFFFFFFFF;
        end
      end
      if (ob[i+1].f_value < ob[i].f_value) begin
        temp_node = ob[i+1];
        ob[i+1] = ob[i];
        ob[i] = temp_node;
      end
    end
    // identify for validity
    for (int i = 0; i < QUEUE_SIZE-1; i++) begin
      if (ib[i].f_value == 32'hFFFFFFFF) begin
        ib_valid [i] = 0;
      end else begin
        ib_valid [i] = 1;
      end
      if (ob[i].f_value == 32'hFFFFFFFF) begin
        ob_valid [i] = 0;
      end else begin
        ob_valid [i] = 1;
      end
    end
  end 

  assign empty = ob_valid == {QUEUE_SIZE{1'b0}};
  assign full = ib_valid == {QUEUE_SIZE-1{1'b1}};

endmodule
