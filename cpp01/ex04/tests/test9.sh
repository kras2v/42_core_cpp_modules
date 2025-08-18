#!/bin/bash
echo "Executing: ./sed_is_for_losers test9.txt café coffee"
./../sed_is_for_losers test9.txt café coffee
echo "---- Before ----"
cat test9.txt
echo "---- After ----"
cat test9.txt.replace
