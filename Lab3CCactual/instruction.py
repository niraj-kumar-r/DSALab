#!/usr/bin/env python

import sys

# Check that a filename was provided as an argument
if len(sys.argv) < 2:
    print('Usage: python count_instructions.py [filename]')
    sys.exit()

# Get the filename from the command line arguments
filename = sys.argv[1]

# Open the disassemble file in read-only mode with ISO-8859-1 encoding
with open(filename, 'r', encoding='ISO-8859-1') as file:
    # Read the entire file into memory
    content = file.read()

    # Split the content into lines
    lines = content.split('\n')

    # Initialize a counter to keep track of the number of instructions
    instruction_count = len(lines)

    # Print the final count of instructions
    print('Number of instructions in', filename, ':', instruction_count)
