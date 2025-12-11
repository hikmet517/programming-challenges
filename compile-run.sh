#!/usr/bin/bash

# takes a cpp file, compiles and runs with input file

file=$1
bin_file="${file%.*}"
input_file="${bin_file}-input.txt"
g++ -lm -lcrypt -std=c++11 -pipe "$file" -o "$bin_file" && ./"$bin_file" < "$input_file"
