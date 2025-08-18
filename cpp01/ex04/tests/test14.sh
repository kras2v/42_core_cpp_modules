#!/bin/bash
echo "Executing: ./sed_is_for_losers test14.txt \","$'\n'"\" \"Wonderful\""
./../sed_is_for_losers test14.txt ",
" ", Wonderful "
echo "---- Before ----"
cat -v test14.txt
echo "---- After ----"
cat -v test14.txt.replace
