#!/bin/bash

# Take the executable as a command line argument
EXECUTABLE=$1

# Compute the instruction count
INSTRUCTION_COUNT=$(perf stat -B -e instructions $EXECUTABLE 2>&1 | awk '/instructions/ {print $1}')

# Compute the CPU time
CPU_TIME=$(perf stat -B -e cycles,cpu-clock $EXECUTABLE 2>&1 | awk '/cpu-clock/ {print $1}')

# Compute the cycle time
CYCLE_TIME=$(perf stat -B -e cycles,cpu-clock $EXECUTABLE 2>&1 | awk '/cycles/ {print $1}')

# Print the results
echo "Instruction Count: $INSTRUCTION_COUNT"
echo "CPU Time: $CPU_TIME"
echo "Cycle Time: $CYCLE_TIME"
