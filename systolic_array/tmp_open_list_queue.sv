module tmp_open_list_queue #(
  parameter width = 32,
  parameter length = 32
)
(
  input  logic clk,
  input  logic reset,

  input  logic insert,
  input  logic pop,

  input  logic [width-1:0] in_f_value,

  output logic [width-1:0] out_f_value,

  output logic full,
  output logic empty
);

localparam l_bits = $clog2(length);

logic [(l_bits+1):0] next_size, curr_size;

logic [length-1:0][width-1:0] IB, next_IB;
logic [length-1:0][width-1:0] OB, next_OB;

// Valid signals
logic [length-1:0] IB_valid;
logic [length-1:0] next_IB_valid;
logic [length-1:0] OB_valid;
logic [length-1:0] next_OB_valid;

// Comparators
logic [length-1:0] less_then_previous_IB;
logic [length-1:0] less_then_next_IB;
logic [length-1:0] less_then_same_OB;
logic [length-1:0] less_then_next_OB;
logic [length-1:0] less_then_next_next_OB;

assign full      = next_size == length;
assign empty     = next_size == '0;

integer i, j;

assign out_f_value = OB[0];

always_comb begin
  // defaults
  next_IB = '1;
  next_OB = OB;
  next_IB_valid = '0;
  next_OB_valid = OB_valid;
  next_size = curr_size;

  if (insert && pop) begin
    next_size = curr_size;
    if ((in_f_value < OB[0]) && (in_f_value < OB[1]) && (!IB_valid[0] || (in_f_value < IB[0]))) begin
      // enqueue directly into outQueue[0]
      next_OB[0] = in_f_value;
      next_OB_valid[0] = 1;
    end else begin
      // enqueue into inQueue[0]
      next_IB[0] = in_f_value;
      next_IB_valid[0] = 1;
      // dequeue outQueue[0]
      next_OB_valid[0] = 0;
      next_OB[0] = '1;
    end
  end else if (insert) begin
    next_size = curr_size + 1;
    if ((in_f_value < OB[0]) && (in_f_value < OB[1]) && (!IB_valid[0] || (in_f_value < IB[0]))) begin
      // enqueue directly into outQueue[0]
      next_OB[0] = in_f_value;
      next_OB_valid[0] = 1;
      // Bump outQueue[0] into inQueue[0]
      next_IB[0] = OB[0];
      next_IB_valid[0] = OB_valid[0];
    end else begin
      // enqueue into inQueue[0]
      next_IB[0] = in_f_value;
      next_IB_valid[0] = 1;
    end
  end else if (pop) begin
    next_size = curr_size - 1;
    next_OB_valid[0] = 0;
    next_OB[0] = '1;
  end

  // Calculate whether inQueue[j] < inQueue[j+1] or inQueue
  less_then_next_IB      = '0;
  less_then_same_OB     = '0;
  less_then_next_OB     = '0;
  less_then_next_next_OB = '0;

  for (j = 0; j < length; j += 1) begin
    // Special handle length at end of queue
    less_then_previous_IB[j]      = (j > 0        ) ? (IB[j] < IB[j-1] ) : !insert || (IB[j] <= in_f_value); // TODO needs to be less than or equals
    less_then_next_IB[j]      = (j < length-1) ? (IB[j] < IB[j+1] ) : 1;

    less_then_same_OB[j]     =                   (OB[j] < OB[j]  )    ;
    less_then_next_OB[j]     = (j < length-1) ? (OB[j] < OB[j+1]) : 1;
    less_then_next_next_OB[j] = (j < length-2) ? (OB[j] < OB[j+2]) : 1;
  end

  // Perform any additional sorting
  for (j = 0; j < length - 1; j += 1) begin
    if (less_then_same_OB[j] && less_then_next_OB[j] && less_then_previous_IB[j]) begin
      // Insert inQueue into empty outQueue slot
      next_OB[j] = IB[j];
      next_OB_valid[j] = IB_valid[j];
    end else if (less_then_next_OB[j] && less_then_next_IB[j] && less_then_next_next_OB[j]) begin
      // Swap inQueue and outQueue
      next_OB[j+1] = IB[j+1];
      next_OB_valid[j+1] = IB_valid[j+1];

      next_IB[j+1] = OB[j];
      next_IB_valid[j+1] = OB_valid[j];
    end else if ((j == length - 2) && !OB_valid[j+1] && IB_valid[j+1]) begin
      next_OB[j+1] = IB[j+1];
      next_OB_valid[j+1] = IB_valid[j+1];
    end else begin
      // Shift inQueue down
      next_IB[j+1] = IB[j];
      next_IB_valid[j+1] = IB_valid[j];
    end
  end

  // Shift outQueue length forward if there is a gap
  for (j = 0; j < length-1; j += 1) begin
    // TODO might not be necessary to check current OB_valid
    if (!OB_valid[j] && !next_OB_valid[j]) begin
      next_OB[j] = OB[j+1];
      next_OB_valid[j] = OB_valid[j+1];
      next_OB[j+1] = '1;
      next_OB_valid[j+1] = 0;
    end
  end
end

always_ff @(posedge clk) begin

  if (reset) begin
    curr_size  <= '0;
    IB_valid  <= '0;
    OB_valid  <= '0;

    for (i = 0; i < length; i += 1) begin
      IB[i]  <= '1;
      OB[i] <= '1;
    end

  end else begin
    curr_size  <= next_size;
    IB         <= next_IB;
    IB_valid   <= next_IB_valid;
    OB         <= next_OB;
    OB_valid   <= next_OB_valid;
  end
end

endmodule
