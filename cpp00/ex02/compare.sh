#!/bin/bash

if [ "$#" -ne 2 ]; then
  echo "Usage: $0 file1 file2"
  exit 1
fi

file1="$1"
file2="$2"

if ! [ -f "$file1" ]; then
  echo "Error: '$file1' not found!"
  exit 1
fi

if ! [ -f "$file2" ]; then
  echo "Error: '$file2' not found!"
  exit 1
fi

diff_output=$(diff "$file1" "$file2")

if [ $? -eq 0 ]; then
  echo "Files are identical."
else
  echo "Files differ:"
  echo "$diff_output"
fi
