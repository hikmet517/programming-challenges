#!/usr/bin/bash

set -e

# takes a cpp file
# compiles and runs with input file
# checks output against output files

file=$1
bin_file="${file%.*}"
g++ -lm -lcrypt -std=c++11 -pipe "$file" -o "$bin_file"

input_file="${bin_file}-input.txt"
output_file="${bin_file}-output.txt"

output_exec_file=$(mktemp)
./"$bin_file" < "$input_file" > "$output_exec_file"
if cmp "$output_exec_file" "$output_file"; then
    echo "PASSED"
else 
    echo "FAILED"
fi
