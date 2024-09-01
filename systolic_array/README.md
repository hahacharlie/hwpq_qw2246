# Systolic Array (Hardware Priority Queue implementation based on Zhou's 2020 paper)

## Required Componenets

`verilator`, `gtkwave`

## Make Commands

`make clean`
This will clean the all verilator auto generated directories and file.
`make sim`
This will verilate the module and run the simulation.
`make waves`
This will verilate the module, run the simulation, and open the waveform according to the saved waveform layout.

## Assertion

In the testbench, the correct order of the output will be asserted in the testbench.
