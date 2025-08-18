#!/bin/bash
echo "Executing: ./sed_is_for_losers test4.txt two 2"
./../sed_is_for_losers test4.txt two 2
echo "---- Before ----"
cat  test4.txt
echo "---- After ----"
cat  test4.txt.replace
