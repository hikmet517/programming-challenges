#!/usr/bin/bash

# iterates over all binary files
# runs them with matching input files
# checks output against output files

for f in *; do

    # check if the file is a binary
    file_out=$(file --brief "$f")
    if [[ "${file_out}" =~ ^ELF ]]; then

        # check if input and output files exist
        input_file="${f}-input.txt"
        output_file="${f}-output.txt"
        if [ -f "${input_file}" ] && [ -f "${output_file}" ]; then
            echo "testing '${f}'"

            # execute and check result against output file
            output_exec_file=$(mktemp)
            ./"$f" < "$input_file" > "$output_exec_file"
            if cmp "$output_exec_file" "$output_file"; then
                echo "PASSED"
            else 
                echo "FAILED"
            fi
        fi
    fi
done
