module register_tree #(
	parameter TREE_DEPTH = 4,
	parameter DATA_WIDTH = 32
)(
    input wire clk,
    input wire reset,
    input wire replace,
    input wire [DATA_WIDTH-1:0] new_item,    // New item for replacing the top
    output reg [DATA_WIDTH-1:0] top_item     // Output the top item
);
    localparam NUM_NODES = (1 << TREE_DEPTH) - 1; // e.g. 16 nodes for depth 4 -> NUM_NODES = 15

    // State machine states
    enum logic [1:0] {
        LOAD = 2'b00,
        IDLE = 2'b01,
        REMOVE_AND_COMPARE_EVEN = 2'b10,
        COMPARE_ODD = 2'b11
    } state;

    // Register array to store the tree nodes
    reg [DATA_WIDTH-1:0] tree [0:NUM_NODES - 1];

    // Wires to connect the comparator units
    wire [DATA_WIDTH-1:0] new_parent [0:NUM_NODES / 2 - 1];         // NUM_NODES/2 - 1 = 7 for depth 4
    wire [DATA_WIDTH-1:0] new_left_child [0:NUM_NODES / 2 - 1];
    wire [DATA_WIDTH-1:0] new_right_child [0:NUM_NODES / 2 - 1];

    // Instantiate comparator units for each applicable node
    genvar i;
    generate
        for (i = 0; i < NUM_NODES / 2; i = i + 1) begin : comparator_units
            comparator #(
                .DATA_WIDTH(DATA_WIDTH)
            ) comparator_inst (
                .parent(tree[i]),
                .left_child(tree[2*i+1]),
                .right_child(tree[2*i+2]),
                .new_parent(new_parent[i]),
                .new_left_child(new_left_child[i]),
                .new_right_child(new_right_child[i])
            );
        end
    endgenerate

    // State machine control
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= LOAD;
        end else begin
            case (state)
                LOAD: begin
                    for (integer j = 0; j < NUM_NODES; j = j + 1) begin
                        tree[j] <= (j + 1) * 10; // Initialize tree entries to fixed values
                    end
                    state <= REMOVE_AND_COMPARE_EVEN;
                end
                IDLE: begin
                end
                REMOVE_AND_COMPARE_EVEN: begin
                    tree[0] <= new_parent[0];
                    tree[1] <= new_left_child[0];
                    tree[2] <= new_right_child[0];
                    if (replace) begin
                        top_item <= tree[0];
                        tree[0] <= new_item;
                    end
                    // Handle even levels
                    for (integer k = 2; k < TREE_DEPTH; k = k + 2) begin
                        for (integer j = 2**k - 1; j <= 2**(k+1) - 2; j = j + 1) begin
                            tree[j] <= new_parent[j];
                            tree[2*j+1] <= new_left_child[j];
                            tree[2*j+2] <= new_right_child[j];
                        end
                    end
                    state <= COMPARE_ODD;
                end
                COMPARE_ODD: begin
                    for (integer m = 1; m < TREE_DEPTH - 1; m = m + 2) begin
                        for (integer n = 2**m - 1; n <= 2**(m+1) - 2; n = n + 1) begin
                            tree[n] <= new_parent[n];
                            tree[2*n+1] <= new_left_child[n];
                            tree[2*n+2] <= new_right_child[n];
                        end
                    end
                    state <= REMOVE_AND_COMPARE_EVEN;
                end
                default: begin
                    state <= IDLE;
                end
            endcase
        end
    end

endmodule

