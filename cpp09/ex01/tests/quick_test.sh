#!/bin/bash

# Quick validation tests for RPN Calculator
# Focus: numbers must be < 10 (single digits only)
echo "=== Quick RPN Validation Tests ==="

echo "Building..."
make > /dev/null 2>&1

echo "1. Basic single digit addition: 3 4 +"
./RPN "3 4 +"

echo "2. Subject example: 8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo "3. Maximum single digits: 9 9 +"
./RPN "9 9 +"

echo "4. Using zero: 0 5 +"
./RPN "0 5 +"

echo "5. Division by zero (error): 5 0 /"
./RPN "5 0 /"

echo "6. INVALID: Multi-digit number: 10 5 +"
./RPN "10 5 +"

echo "7. INVALID: Large numbers: 25 30 +"
./RPN "25 30 +"

echo "8. INVALID: Negative number: -1 2 +"
./RPN "-1 2 +"

echo "9. INVALID: Decimal number: 1.5 2 +"
./RPN "1.5 2 +"

echo "10. INVALID: Missing argument:"
./RPN

echo "11. INVALID: Single number only: 5"
./RPN "5"

echo "12. Test all single digits work: 1 2 3 4 5 6 7 8 9 + + + + + + + +"
./RPN "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +"

echo "=== End Quick Tests ==="
