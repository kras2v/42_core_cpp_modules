#!/bin/bash
echo "Executing: ./sed_is_for_losers test21.txt ipsum IPSUM"
./../sed_is_for_losers test21.txt ipsum IPSUM
echo "---- Before ----"
grep -n ipsum test21.txt | head -n 5
echo "---- After ----"
grep -n IPSUM test21.txt.replace | head -n 5
