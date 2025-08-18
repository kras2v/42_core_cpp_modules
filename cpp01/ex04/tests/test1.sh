#!/bin/bash
echo "Executing: ./sed_is_for_losers test1.txt Hello Hi"
./../sed_is_for_losers test1.txt Hello Hi
echo "---- Before ----"
cat test1.txt
echo "---- After ----"
cat test1.txt.replace
