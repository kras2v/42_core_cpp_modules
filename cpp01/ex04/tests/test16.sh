#!/bin/bash
echo "Executing: ./sed_is_for_losers test16.txt Alice Bob"
./../sed_is_for_losers test16.txt Alice Bob
echo "---- Before ----"
head -n 10 test16.txt
echo "..."
echo "---- After ----"
head -n 10 test16.txt.replace
