module bram_tree (
    input logic clk,
    input logic rst,
    input logic replace,
    input logic [31:0] new_item,
    output logic [31:0] top_item
);

  // BRAM interface signals
  logic [3:0] bram_addr_a[0:3];
  logic [3:0] bram_addr_b[0:3];
  logic [31:0] bram_din_a[0:3];
  logic [31:0] bram_din_b[0:3];
  logic bram_we_a[0:3];
  logic bram_we_b[0:3];
  logic [31:0] bram_dout_a[0:3];
  logic [31:0] bram_dout_b[0:3];

  // Comparator signals
  logic [31:0] parent[0:6];
  logic [31:0] left_child[0:6];
  logic [31:0] right_child[0:6];
  logic [31:0] new_parent[0:6];
  logic [31:0] new_left_child[0:6];
  logic [31:0] new_right_child[0:6];

  // Generate 4 BRAMs
  genvar i;
  generate
    for (i = 0; i < 4; i++) begin : BRAM_gen
      xilinx_true_dual_port_read_first_1_clock_ram #(
          .RAM_WIDTH(32),
          .RAM_DEPTH(2 ** i),
          .RAM_PERFORMANCE("HIGH_PERFORMANCE"),
          .INIT_FILE("")
      ) bram (
          .addra(bram_addr_a[i]),  // Port A address bus, width determined from RAM_DEPTH
          .addrb(bram_addr_b[i]),  // Port B address bus, width determined from RAM_DEPTH
          .dina(bram_din_a[i]),  // Port A RAM input data, width determined from RAM_WIDTH
          .dinb(bram_din_b[i]),  // Port B RAM input data, width determined from RAM_WIDTH
          .clka(clk),  // Clock
          .wea(bram_we_a[i]),  // Port A write enable
          .web(bram_we_b[i]),  // Port B write enable
          .ena(1'b1),       // Port A RAM Enable, for additional power savings, disable port when not in use
          .enb(1'b1),       // Port B RAM Enable, for additional power savings, disable port when not in use
          .rsta(rst),  // Port A output reset (does not affect memory contents)
          .rstb(rst),  // Port B output reset (does not affect memory contents)
          .regcea(1'b1),  // Port A output register enable
          .regceb(1'b1),  // Port B output register enable
          .douta(bram_dout_a[i]),  // Port A RAM output data, width determined from RAM_WIDTH
          .doutb(bram_dout_b[i])  // Port B RAM output data, width determined from RAM_WIDTH
      );
    end
  endgenerate

  generate
    for (i = 0; i < 7; i++) begin : comparator_gen
      comparator #(
          .DATA_WIDTH(32)
      ) comparator (
          .parent(parent[i]),
          .left_child(left_child[i]),
          .right_child(right_child[i]),
          .new_parent(new_parent[i]),
          .new_left_child(new_left_child[i]),
          .new_right_child(new_right_child[i])
      );
    end
  endgenerate

  enum logic [1:0] {
    REPLACE = 2'b00,
    EVEN = 2'b01,
    ODD = 2'b10,
    IDLE = 2'b11
  } STATE;

  // logic even_odd_flag;
  integer level, addr, done_flag;
  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      for (int j = 0; j < 4; j++) begin
        bram_addr_a[j] <= '0;
        bram_addr_b[j] <= '0;
        bram_we_a[j]   <= '0;
        bram_din_a[j]  <= '0;
        bram_we_b[j]   <= '0;
        bram_din_b[j]  <= '0;
      end
      for (int k = 0; k < 7; k++) begin
        parent[k]          <= '0;
        left_child[k]      <= '0;
        right_child[k]     <= '0;
        new_parent[k]      <= '0;
        new_left_child[k]  <= '0;
        new_right_child[k] <= '0;
      end
      level <= 0;
      addr <= 0;
      // even_odd_flag <= 0;
      done_flag <= 0;
      STATE <= IDLE;
    end else begin
      case (STATE)
        IDLE: begin
          if (replace) begin
            STATE <= REPLACE;
          end else begin
            STATE <= EVEN;
          end
        end

        REPLACE: begin
          bram_addr_b[0] <= '0;
          bram_din_b[0] <= new_item;
          bram_we_b[0] <= '1;
          STATE <= EVEN;
        end

        EVEN: begin
          // close all wea ports just in case 
          for (int k = 0; k < 4; k++) begin
            bram_we_a[k] <= '0;
            bram_we_b[k] <= '0;
          end

          for (level = 0; level < 4; level = level + 2) begin
            if (level != 3) begin  // not equal to second last level
              if (addr < (1 << level)) begin
                if (addr == 3) begin
                  done_flag <= 1;
                end
                bram_addr_b[level]             <= addr;
                bram_addr_a[level+1]           <= (addr << 1);
                bram_addr_b[level+1]           <= (addr << 1) + 1;

                // read from BRAMs
                parent[(1<<level)-1+addr]      <= bram_dout_b[level];
                left_child[(1<<level)-1+addr]  <= bram_dout_a[level+1];
                right_child[(1<<level)-1+addr] <= bram_dout_b[level+1];

                // get results from comparators
                bram_din_b[level]              <= new_parent[(1<<level)-1+addr];
                bram_din_a[level+1]            <= new_left_child[(1<<level)-1+addr];
                bram_din_b[level+1]            <= new_right_child[(1<<level)-1+addr];

                // write into BRAMS
                // bram_we_b[level]               <= '1;
                // bram_we_a[level+1]             <= '1;
                // bram_we_b[level+1]             <= '1;
              end
            end
          end

          if (replace) begin
            STATE <= REPLACE;
          end else if (done_flag == 1) begin
            level <= 0;
            addr <= 0;
            // even_odd_flag <= 0;
            done_flag <= 0;
            STATE <= ODD;
          end else begin
            addr <= addr + 1;
          end
        end

        ODD: begin
          // close all wea ports
          for (int k = 0; k < 4; k++) begin
            bram_we_a[k] <= '0;
            bram_we_b[k] <= '0;
          end

          for (level = 1; level < 4; level = level + 2) begin
            if (level != 3) begin  // not equal to second last level
              if (addr < (1 << level)) begin
                if (addr == 1) begin
                  done_flag <= 1;
                end
                bram_addr_b[level]             <= addr;
                bram_addr_a[level+1]           <= (addr << 1);
                bram_addr_b[level+1]           <= (addr << 1) + 1;

                // read from BRAMs
                parent[(1<<level)-1+addr]      <= bram_dout_b[level];
                left_child[(1<<level)-1+addr]  <= bram_dout_a[level+1];
                right_child[(1<<level)-1+addr] <= bram_dout_b[level+1];

                // get results from comparators
                bram_din_b[level]              <= new_parent[(1<<level)-1+addr];
                bram_din_a[level+1]            <= new_left_child[(1<<level)-1+addr];
                bram_din_b[level+1]            <= new_right_child[(1<<level)-1+addr];

                // write into BRAMS
                // bram_we_b[level]               <= '1;
                // bram_we_a[level+1]             <= '1;
                // bram_we_b[level+1]             <= '1;
              end
            end
          end

          if (replace) begin
            STATE <= REPLACE;
          end else if (done_flag == 1) begin
            level <= 0;
            addr <= 0;
            done_flag <= 0;
            // even_odd_flag <= 0;
            STATE <= EVEN;
          end else begin
            addr <= addr + 1;
          end
        end

        // WRITE: begin
        //   for (int k = 0; k < 4; k++) begin
        //     bram_we_a[k] <= '1;
        //     bram_we_b[k] <= '1;
        //   end

        //   if (even_odd_flag == 0) begin
        //     STATE <= EVEN;
        //   end else begin
        //     STATE <= ODD;
        //   end
        // end
      endcase
    end
  end

  // Reserve port A on BRAM 0 to read continously
  assign bram_addr_a[0] = '0;
  assign top_item = bram_dout_a[0];

endmodule
