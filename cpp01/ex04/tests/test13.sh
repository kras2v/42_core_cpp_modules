#!/bin/bash
echo "Executing: ./sed_is_for_losers test13.txt \"red"$'\n'"violets\" \"red & violets\""
./../sed_is_for_losers test13.txt "red
violets" "red & violets"
echo "---- Before ----"
cat -v test13.txt
echo "---- After ----"
cat -v test13.txt.replace
