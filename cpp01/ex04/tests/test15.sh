#!/bin/bash
echo "Executing: ./sed_is_for_losers test15.txt \"one."$'\n'"This\" \"one, This\""
./../sed_is_for_losers test15.txt "one.
This" "one, This"
echo "---- Before ----"
cat -v test15.txt
echo "---- After ----"
cat -v test15.txt.replace
