#!/bin/bash
echo "Executing: ./sed_is_for_losers test8.txt "aa" "b""
./../sed_is_for_losers test8.txt "aa" "b"
echo "---- Before ----"
cat test8.txt
echo "---- After ----"
cat test8.txt.replace
