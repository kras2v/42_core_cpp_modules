#!/bin/bash
echo "Executing: ./sed_is_for_losers test6.txt remove """
./../sed_is_for_losers test6.txt remove ""
echo "---- Before ----"
cat test6.txt
echo "---- After ----"
cat test6.txt.replace
