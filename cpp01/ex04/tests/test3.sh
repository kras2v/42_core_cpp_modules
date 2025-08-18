#!/bin/bash
echo "Executing: ./sed_is_for_losers test3.txt apple orange"
./../sed_is_for_losers test3.txt apple orange
echo "---- Before ----"
cat test3.txt
echo "---- After ----"
cat test3.txt.replace
