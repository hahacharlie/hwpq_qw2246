module tmp_open_list_queue_tb;
  // Parameters matching the module under test
  parameter QUEUE_SIZE = 4;
  parameter DATA_WIDTH = 32;

  // Clock and reset signals
  logic                  CLK;
  logic                  RSTn;

  // Input signals to the module
  logic                  i_wrt;  // Enqueue signal
  logic                  i_read;  // Dequeue signal
  logic                  i_valid;  // Input data valid
  logic [DATA_WIDTH-1:0] i_node_f;  // Node data input

  // Output signals from the module
  logic                  o_full;  // Queue is full
  logic                  o_empty;  // Queue is empty
  logic                  o_valid;  // Output data valid
  logic [DATA_WIDTH-1:0] o_node_f;  // Node data output

  // Instantiate the tmp_open_list_queue module
  tmp_open_list_queue #(
      .QUEUE_SIZE(QUEUE_SIZE),
      .DATA_WIDTH(DATA_WIDTH)
  ) uut (
      .CLK(CLK),
      .RSTn(RSTn),
      .i_wrt(i_wrt),
      .i_read(i_read),
      .i_valid(i_valid),
      .i_node_f(i_node_f),
      .o_full(o_full),
      .o_empty(o_empty),
      .o_valid(o_valid),
      .o_node_f(o_node_f)
  );

  // Clock generation: 10ns period (100MHz)
  always #5 CLK <= ~CLK;

  // Test variables
  integer i;

  initial begin
    // Initialize signals
    CLK      = 0;
    RSTn     = 0;
    i_wrt    = 0;
    i_read   = 0;
    i_valid  = 0;
    i_node_f = 0;

    // Display header
    $display("Time\tRSTn\ti_wrt\ti_read\ti_valid\ti_node_f\to_full\to_empty\to_valid\to_node_f");
    $monitor("%0dns\t%b\t%b\t%b\t%b\t%h\t%b\t%b\t%b\t%h", $time, RSTn, i_wrt, i_read, i_valid,
             i_node_f, o_full, o_empty, o_valid, o_node_f);

    // Reset the module
    @(posedge CLK);
    RSTn = 1;
    @(posedge CLK);

    // Test Case 1: Enqueue nodes
    // Enqueue nodes with values 20, 10, 30, 5
    // Expected: Nodes should be sorted in OB based on 'f' value
    $display("\nTest Case 1: Enqueue nodes");
    enqueue_node(32'h00000014);  // f = 20
    enqueue_node(32'h0000000A);  // f = 10
    enqueue_node(32'h0000001E);  // f = 30
    enqueue_node(32'h00000005);  // f = 5

    // Wait for sorting to complete
    repeat (2) @(posedge CLK);

    // Test Case 2: Dequeue nodes
    // Dequeue all nodes and observe the order
    $display("\nTest Case 2: Dequeue nodes");
    for (i = 0; i < QUEUE_SIZE; i++) begin
      dequeue_node();
      @(posedge CLK);
    end

    // Test Case 3: Enqueue and Dequeue simultaneously
    $display("\nTest Case 3: Enqueue and Dequeue simultaneously");
    enqueue_node(32'h00000018);  // f = 24
    enqueue_node(32'h0000000C);  // f = 12
    @(posedge CLK);
    i_wrt = 1;
    i_read = 1;
    i_valid = 1;
    i_node_f = 32'h00000008;  // f = 8
    @(posedge CLK);
    i_wrt   = 0;
    i_read  = 0;
    i_valid = 0;

    // Wait and then dequeue remaining nodes
    repeat (2) @(posedge CLK);
    while (!o_empty) begin
      dequeue_node();
      @(posedge CLK);
    end

    // Test Case 4: Attempt to enqueue when full
    $display("\nTest Case 4: Attempt to enqueue when full");
    for (i = 0; i < 2 * QUEUE_SIZE; i++) begin
      enqueue_node(32'h00000010 + i);  // f = 16 + i
      @(posedge CLK);
    end

    // Test Case 5: Attempt to dequeue when empty
    $display("\nTest Case 5: Attempt to dequeue when empty");
    @(posedge CLK);
    while (!o_empty) begin
      dequeue_node();
      @(posedge CLK);
    end
    dequeue_node();  // Attempt to dequeue when empty
    @(posedge CLK);

    // Finish simulation
    repeat (2) @(posedge CLK);
    $finish;
  end

  // Task to perform an enqueue operation
  task enqueue_node(input logic [DATA_WIDTH-1:0] node_f);
    begin
      if (!o_full) begin
        i_wrt = 1;
        i_valid = 1;
        i_node_f = node_f;
        @(posedge CLK);
        i_wrt   = 0;
        i_valid = 0;
        // i_node_f = 0;
        @(posedge CLK);
      end else begin
        $display("Queue is full. Cannot enqueue node with f = %h", node_f);
      end
    end
  endtask

  // Task to perform a dequeue operation
  task dequeue_node();
    begin
      if (!o_empty) begin
        i_read = 1;
        @(posedge CLK);
        i_read = 0;
        @(posedge CLK);
      end else begin
        $display("Queue is empty. Cannot dequeue.");
      end
    end
  endtask

endmodule
