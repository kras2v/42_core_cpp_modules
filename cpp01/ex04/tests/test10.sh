#!/bin/bash
echo "Executing: ./sed_is_for_losers test10.txt xxx yyy"
./../sed_is_for_losers test10.txt xxx yyy
echo "---- Before ----"
cat test10.txt
echo "---- After ----"
cat test10.txt.replace
