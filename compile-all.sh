#!/usr/bin/bash

for f in *.cpp; do
    echo "compiling '${f}'"
    g++ -lm -lcrypt -std=c++11 -pipe "${f}" -o "${f%.*}"
done
