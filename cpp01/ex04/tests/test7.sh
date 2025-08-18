#!/bin/bash
echo "Executing: ./sed_is_for_losers test7.txt "thisisverylongstring" "X""
./../sed_is_for_losers test7.txt "thisisverylongstring" "X"
echo "---- Before ----"
cat test7.txt
echo "---- After ----"
cat test7.txt.replace
