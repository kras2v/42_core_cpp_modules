#!/bin/bash
echo "Executing: ./sed_is_for_losers test23.txt delete ''"
./../sed_is_for_losers test23.txt delete ""
echo "---- Before ----"
head -n 3 test23.txt
echo "---- After ----"
head -n 3 test23.txt.replace
