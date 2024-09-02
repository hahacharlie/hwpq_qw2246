module register_array_tb;

    // Parameters
    parameter QUEUE_SIZE = 4;
    parameter WIDTH = 32;

    // Testbench signals
    logic clk;
    logic [WIDTH-1:0] new_entry;
    logic [WIDTH-1:0] top_entry;

    // Instantiate the register_array module
    register_array #(
        .QUEUE_SIZE(QUEUE_SIZE),
        .WIDTH(WIDTH)
    ) uut (
        .clk(clk),
        .new_entry(new_entry),
        .top_entry(top_entry)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 10 time units period
    end

    // Test sequence
    initial begin
        // Initialize inputs
        new_entry = 0;

        // Wait for a few clock cycles
        #20;

        // Apply test vectors
        new_entry = 32'hA; #10; // Insert 10
        new_entry = 32'h5; #10; // Insert 5
        new_entry = 32'hF; #10; // Insert 15
        new_entry = 32'h1; #10; // Insert 1

        // Wait for a few clock cycles to observe the output
        #50;

        // Finish simulation
        $finish;
    end

    // Monitor the output
    initial begin
        $monitor("At time %t, new_entry = %h, top_entry = %h", $time, new_entry, top_entry);
    end

endmodule