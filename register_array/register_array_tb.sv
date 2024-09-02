module register_array_tb;

    // Parameters
    parameter QUEUE_SIZE = 8;
    parameter DATA_WIDTH = 32;

    // Testbench signals
    logic clk;
    logic [DATA_WIDTH-1:0] new_entry;
    logic [DATA_WIDTH-1:0] max_entry;
    logic replace;

    // Instantiate the priority_queue module
    register_array #(
        .QUEUE_SIZE(QUEUE_SIZE),
        .DATA_WIDTH(DATA_WIDTH)
    ) uut (
        .clk(clk),
        .replace(replace),
        .new_entry(new_entry),
        .max_entry(max_entry)
    );

    // Clock generation
    always #5 clk <= ~clk;

    // Test sequence
    initial begin
        
        // Initialize inputs
        clk = 0;
        replace = 0;
        new_entry = 0;

        // Waveform generation
        $dumpfile("register_array_tb.vcd");
        $dumpvars(0, register_array_tb);

        // Wait for a few clock cycles
        repeat (8) @(posedge clk);
        
        // Test case 1: Insert items in ascending order
        for (int i = 1; i <= 4; i++) begin
            @(posedge clk);
            replace = 1;
            new_entry = i * 10;
            @(posedge clk);
            replace = 0;
            repeat (2) @(posedge clk);
            $display("max_entry: %d", max_entry);
        end

        // Wait for a few clock cycles to observe the output
        repeat (2) @(posedge clk);

        // Finish simulation
        $finish;
    end

endmodule
