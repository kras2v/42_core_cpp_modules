#!/bin/bash
echo "Executing: ./sed_is_for_losers test17.txt , ;"
./../sed_is_for_losers test17.txt , ";"
echo "---- Before ----"
head -n 10 test17.txt
echo "..."
echo "---- After ----"
head -n 10 test17.txt.replace
