# Makefile for running verilator binary simulation

MODULE=open_list_queue

.PHONY:sim
sim: waveform.vcd

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:waves
waves: waveform.vcd
	@echo
	@echo "### WAVES ###"
	gtkwave tb_$(MODULE).vcd -a gtkwave_setup.gtkw

waveform.vcd: .stamp.verilate
	@echo
	@echo "### SIMULATING ###"
	./obj_dir/Vtb_$(MODULE)
	@touch .stamp.simulate

.stamp.verilate: $(MODULE).sv
	@echo
	@echo "### VERILATING ###"
	verilator -j 0 -Wall --timing --trace --clk CLK --x-assign unique --x-initial unique -threads 8 --trace-coverage --trace-max-array 256 --trace-params --trace-structs --binary tb_$(MODULE).sv
	@touch .stamp.verilate

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf tb_$(MODULE).vcd
