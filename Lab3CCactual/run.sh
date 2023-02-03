#!/bin/bash

# Define the number of times to run perf stat
N=10

# Get the executable file or system command as the first command line argument
executable="$1"

# Get the name of the output CSV file as an optional second command line argument
filename=${2:-perf_stat_results.csv}

# Remove the file if it already exists
rm -f $filename

# Write the header of the CSV file
echo "Iteration,Instructions" > $filename

# Initialize a variable to store the sum of instructions
sum=0

# Loop over the number of iterations
for i in $(seq 1 $N); do
  # Run perf stat and extract the number of instructions
  result=$(perf stat -e instructions sh -c "$executable" 2>&1 | grep 'instructions' | awk '{print $1}' | sed 's/,//g')

  # Add a row to the CSV file with the iteration number and number of instructions
  echo "$i,$result" >> $filename

  # Increment the sum of instructions
  sum=$(echo "$sum + $result" | bc)
done

# Calculate the average number of instructions
average=$(echo "$sum / $N" | bc)

# Add a row to the CSV file with the average number of instructions
echo "Average,$average" >> $filename
