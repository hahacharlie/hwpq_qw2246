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

    // Wires to connect the comparetor units
    wire [DATA_WIDTH-1:0] new_parent [0:NUM_NODES / 2 - 1];         // NUM_NODES/2 - 1 = 7 for depth 4
    wire [DATA_WIDTH-1:0] new_left_child [0:NUM_NODES / 2 - 1];
    wire [DATA_WIDTH-1:0] new_right_child [0:NUM_NODES / 2 - 1];

    // Instantiate comparetor units for each applicable node
    genvar i;
    generate
        for (i = 0; i < NUM_NODES / 2; i = i + 1) begin : comparetor_units
            comparetor #(
                .DATA_WIDTH(DATA_WIDTH)
            ) comparetor_inst (
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
                    // Initialize tree entries to fixed values
                    tree[0] <= 10;
                    tree[1] <= 20;
                    tree[2] <= 30;
                    tree[3] <= 40;
                    tree[4] <= 50;
                    tree[5] <= 60;
                    tree[6] <= 70;
                    tree[7] <= 80;
                    tree[8] <= 90;
                    tree[9] <= 100;
                    tree[10] <= 110;
                    tree[11] <= 120;
                    tree[12] <= 130;
                    tree[13] <= 140;
                    tree[14] <= 150;
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
                    tree[3] <= new_parent[3];
                    tree[7] <= new_left_child[3];
                    tree[8] <= new_right_child[3];
                    tree[4] <= new_parent[4];
                    tree[9] <= new_left_child[4];
                    tree[10] <= new_right_child[4];
                    tree[5] <= new_parent[5];
                    tree[11] <= new_left_child[5];
                    tree[12] <= new_right_child[5];
                    tree[6] <= new_parent[6];
                    tree[13] <= new_left_child[6];
                    tree[14] <= new_right_child[6];
                    state <= COMPARE_ODD;
                end
                COMPARE_ODD: begin
                    tree[1] <= new_parent[1];
                    tree[3] <= new_left_child[1];
                    tree[4] <= new_right_child[1];
                    tree[2] <= new_parent[2];
                    tree[5] <= new_left_child[2];
                    tree[6] <= new_right_child[2];
                    state <= REMOVE_AND_COMPARE_EVEN;
                end
                default: begin
                    state <= IDLE;
                end
            endcase
        end
    end

endmodule
