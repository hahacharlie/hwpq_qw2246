module register_tree_tb;
    parameter TREE_DEPTH = 4;
    parameter DATA_WIDTH = 32;

    reg clk;
    reg replace;
    reg [DATA_WIDTH-1:0] new_item;
    wire [DATA_WIDTH-1:0] top_item;

    register_tree #(
        .TREE_DEPTH(TREE_DEPTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) dut (
        .clk(clk),
        .replace(replace),
        .new_item(new_item),
        .top_item(top_item)
    );

    // Clock generation
    always #5 clk <= ~clk;

    // Test stimulus
    initial begin
        // Initialize signals
        clk = 0;
        replace = 0;
        new_item = 0;

        // Waveform generation
        $dumpfile("register_tree_tb.vcd");  // Specify the dump file name
        $dumpvars(0, register_tree_tb);     // Dump all variables in the module

        repeat (TREE_DEPTH) @(posedge clk);

        // Test case 1: Insert items in ascending order
        for (int i = 1; i <= (1 << TREE_DEPTH); i++) begin
            @(posedge clk);
            replace = 1;
            new_item = i;
            @(posedge clk);
            replace = 0;
            repeat (2) @(posedge clk);
        end

        // Test case 2: Insert items in descending order
        for (int i = (1 << TREE_DEPTH); i >= 1; i--) begin
            @(posedge clk);
            replace = 1;
            new_item = i;
            @(posedge clk);
            replace = 0;
            repeat (2) @(posedge clk);
        end

        // Test case 3: Insert random items
        for (int i = 0; i < 20; i++) begin
            @(posedge clk);
            replace = 1;
            new_item = $urandom_range(1, 100);
            @(posedge clk);
            replace = 0;
            repeat (2) @(posedge clk);
        end

        // Test case 4: Insert duplicate items
        for (int i = 0; i < 10; i++) begin
            @(posedge clk);
            replace = 1;
            new_item = 50;
            @(posedge clk);
            replace = 0;
            repeat (2) @(posedge clk);
        end

        // Test case 5: Insert alternating large and small items
        for (int i = 0; i < 10; i++) begin
            @(posedge clk);
            replace = 1;
            new_item = (i % 2 == 0) ? 1000 : 1;
            @(posedge clk);
            replace = 0;
            repeat (2) @(posedge clk);
        end

        // Finish simulation
        repeat (2) @(posedge clk); 
        $finish;
    end

    // Monitor top item
    always @(posedge clk) begin
        if (replace) begin
            $display("Top item is %0d, new item is %0d", top_item, new_item);
        end
    end
endmodule
