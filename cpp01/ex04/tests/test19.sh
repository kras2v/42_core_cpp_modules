#!/bin/bash
echo "Executing: ./sed_is_for_losers test19.txt "d1\nword1" 'JOINED'"
./../sed_is_for_losers test19.txt "0
word1" "JOINED"
echo "---- Before ----"
grep -n "word1" test19.txt | head -n 3
echo "---- After ----"
grep -n "JOINED" test19.txt.replace | head -n 3
