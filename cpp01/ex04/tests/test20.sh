#!/bin/bash
echo "Executing: ./sed_is_for_losers test20.txt café coffee"
./../sed_is_for_losers test20.txt café coffee
echo "---- Before ----"
head -n 5 test20.txt
echo "---- After ----"
head -n 5 test20.txt.replace
