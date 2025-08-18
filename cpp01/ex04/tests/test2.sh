#!/bin/bash
echo "Executing: ./sed_is_for_losers test2.txt cat mouse"
./../sed_is_for_losers test2.txt cat mouse
echo "---- Before ----"
cat test2.txt
echo "---- After ----"
cat test2.txt.replace
