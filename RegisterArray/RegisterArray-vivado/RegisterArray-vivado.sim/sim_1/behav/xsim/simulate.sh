#!/bin/bash -f
# ****************************************************************************
# Vivado (TM) v2024.2 (64-bit)
#
# Filename    : simulate.sh
# Simulator   : AMD Vivado Simulator
# Description : Script for simulating the design by launching the simulator
#
# Generated by Vivado on Tue Apr 01 19:41:22 EDT 2025
# SW Build 5239630 on Fri Nov 08 22:34:34 MST 2024
#
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
#
# usage: simulate.sh
#
# ****************************************************************************
set -Eeuo pipefail
# simulate design
echo "xsim RegisterArray_tb_behav -key {Behavioral:sim_1:Functional:RegisterArray_tb} -tclbatch RegisterArray_tb.tcl -view /home/charlie-wu/Workspace/hwpq_qw2246/RegisterArray/RegisterArray-vivado/RegisterArray_tb_behav.wcfg -log simulate.log"
xsim RegisterArray_tb_behav -key {Behavioral:sim_1:Functional:RegisterArray_tb} -tclbatch RegisterArray_tb.tcl -view /home/charlie-wu/Workspace/hwpq_qw2246/RegisterArray/RegisterArray-vivado/RegisterArray_tb_behav.wcfg -log simulate.log

