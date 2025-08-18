#!/bin/bash
echo "Executing: ./sed_is_for_losers test25.txt line 'LINE\nBREAK'"
./../sed_is_for_losers test25.txt line $'LINE\nBREAK'
echo "---- Before ----"
head -n 5 test25.txt
echo "---- After ----"
head -n 10 test25.txt.replace
