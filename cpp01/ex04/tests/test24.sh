#!/bin/bash
echo "Executing: ./sed_is_for_losers test24.txt ### ---"
./../sed_is_for_losers test24.txt "###" "---"
echo "---- Before ----"
head -n 5 test24.txt
echo "---- After ----"
head -n 5 test24.txt.replace
