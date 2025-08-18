#!/bin/bash
echo "Executing: ./sed_is_for_losers test11.txt \"c"$'\n'"c\" \"-\""
./../sed_is_for_losers test11.txt "c
c" "-"
echo "---- Before ----"
cat -v test11.txt
echo "---- After ----"
cat -v test11.txt.replace
