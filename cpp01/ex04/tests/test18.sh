#!/bin/bash
echo "Executing: ./sed_is_for_losers test18.txt $'\t' ' | '"
./../sed_is_for_losers test18.txt $'\t' " | "
echo "---- Before ----"
head -n 5 test18.txt | cat
echo "..."
echo "---- After ----"
head -n 5 test18.txt.replace | cat
