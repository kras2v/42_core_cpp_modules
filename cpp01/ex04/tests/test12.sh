#!/bin/bash


echo "Executing: ./sed_is_for_losers test12.txt \"1"$'\n'"l\" \"1 l\""
./../sed_is_for_losers test12.txt "1
l" "1 l"
echo "---- Before ----"
cat -v test12.txt
echo "---- After ----"
cat -v test12.txt.replace
