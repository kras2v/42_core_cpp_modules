#!/bin/bash
echo "Executing: ./sed_is_for_losers test22.txt a abc"
./../sed_is_for_losers test22.txt a abc
echo "---- Before ----"
head -n 3 test22.txt
echo "---- After ----"
head -n 3 test22.txt.replace
