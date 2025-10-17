#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Test counter
TOTAL_TESTS=0
PASSED_TESTS=0

echo -e "${BLUE}=== RPN Calculator Test Suite ===${NC}"
echo

# Function to run a test
run_test() {
    local test_name="$1"
    local input="$2"
    local expected_output="$3"
    local expected_behavior="$4"  # "success" or "error"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    echo -e "${YELLOW}Test ${TOTAL_TESTS}: ${test_name}${NC}"
    echo "Input: $input"
    echo "Expected: $expected_output ($expected_behavior)"
    echo -e "${BLUE}Output:${NC}"
    
    output=$(./RPN "$input" 2>&1)
    exit_code=$?
    
    echo "$output"
    echo "Exit code: $exit_code"
    
    case "$expected_behavior" in
        "success")
            if [ $exit_code -eq 0 ] && [ "$output" = "$expected_output" ]; then
                echo -e "${GREEN}✅ PASS${NC}"
                PASSED_TESTS=$((PASSED_TESTS + 1))
            else
                echo -e "${RED}❌ FAIL: Expected '$expected_output' but got '$output'${NC}"
            fi
            ;;
        "error")
            if [ $exit_code -ne 0 ] && [ "$output" = "$expected_output" ]; then
                echo -e "${GREEN}✅ PASS${NC}"
                PASSED_TESTS=$((PASSED_TESTS + 1))
            else
                echo -e "${RED}❌ FAIL: Expected error with '$expected_output' but got '$output'${NC}"
            fi
            ;;
    esac
    
    echo
    echo "----------------------------------------"
    echo
}

# Build the program
echo -e "${BLUE}Building RPN Calculator...${NC}"
make re
if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Build failed! Cannot run tests.${NC}"
    exit 1
fi
echo -e "${GREEN}✅ Build successful${NC}"
echo

# === VALID TESTS (numbers < 10) ===

# Basic single digit arithmetic
run_test "Simple addition" "3 4 +" "7" "success"
run_test "Simple subtraction" "9 3 -" "6" "success"
run_test "Simple multiplication" "4 5 *" "20" "success"
run_test "Simple division" "8 2 /" "4" "success"

# Test all single digits (0-9)
run_test "Using digit 0" "0 5 +" "5" "success"
run_test "Using digit 1" "1 8 +" "9" "success"
run_test "Using digit 2" "2 6 +" "8" "success"
run_test "Using digit 3" "3 4 +" "7" "success"
run_test "Using digit 4" "4 3 +" "7" "success"
run_test "Using digit 5" "5 2 +" "7" "success"
run_test "Using digit 6" "6 1 +" "7" "success"
run_test "Using digit 7" "7 0 +" "7" "success"
run_test "Using digit 8" "8 1 -" "7" "success"
run_test "Using digit 9" "9 2 -" "7" "success"

# Given example from subject
run_test "Subject example" "8 9 * 9 - 9 - 9 - 4 - 1 +" "42" "success"

# Complex expressions with single digits only
run_test "Multiple operations" "1 2 + 3 4 + *" "21" "success"
run_test "Chain operations" "5 3 - 2 +" "4" "success"
run_test "All four operations" "8 2 / 3 + 1 - 2 *" "12" "success"
run_test "Maximum digits" "9 9 *" "81" "success"
run_test "Subtraction result negative" "3 7 -" "-4" "success"

# Edge cases with single digits
run_test "Zero in calculations" "0 5 +" "5" "success"
run_test "Zero multiplication" "0 9 *" "0" "success"
run_test "Zero division result" "0 7 /" "0" "success"
run_test "Division by zero" "5 0 /" "Error" "error"

# === INVALID TESTS (numbers >= 10) ===

# Multi-digit numbers (should fail)
run_test "Two digit number" "10 5 +" "Error" "error"
run_test "Large numbers" "25 30 +" "Error" "error"
run_test "Three digit numbers" "100 200 +" "Error" "error"
run_test "Mixed single and multi-digit" "5 10 +" "Error" "error"
run_test "Mixed multi-digit and single" "12 3 +" "Error" "error"

# Negative numbers (< 0, violates < 10 rule)
run_test "Negative number" "-1 2 +" "Error" "error"
run_test "Negative single digit" "-5 3 +" "Error" "error"
run_test "Mixed negative positive" "5 -2 +" "Error" "error"

# Floating point numbers (not integers < 10)
run_test "Decimal number" "1.5 2 +" "Error" "error"
run_test "Float with single digit" "5.0 3 +" "Error" "error"
run_test "Small decimal" "0.5 1 +" "Error" "error"

# === STRUCTURAL ERROR TESTS ===

# Insufficient operands
run_test "Single number only" "5" "Error" "error"
run_test "Missing second operand" "5 +" "Error" "error"
run_test "Only operator" "+" "Error" "error"

# Too many operands
run_test "Three numbers one operator" "1 2 3 +" "Error" "error"
run_test "Too many numbers" "1 2 3 4 +" "Error" "error"

# Wrong operator count
run_test "Too many operators" "1 2 + +" "Error" "error"
run_test "Consecutive operators" "1 + - 2" "Error" "error"

# Invalid characters
run_test "Letter in expression" "1 2 a +" "Error" "error"
run_test "Special characters" "1 2 # +" "Error" "error"
run_test "Invalid operator" "1 2 %" "Error" "error"

# Format errors
run_test "No spaces between tokens" "12+" "Error" "error"
run_test "Extra spaces" "1  2  +" "Error" "error"
run_test "Leading spaces" " 1 2 +" "Error" "error"
run_test "Trailing spaces" "1 2 + " "Error" "error"
run_test "Empty string" "" "Error" "error"

# Order errors  
run_test "Operator first" "+ 1 2" "Error" "error"
run_test "Wrong RPN order" "1 + 2" "Error" "error"

# === BOUNDARY TESTS FOR SINGLE DIGITS ===

# Test boundary of single digit constraint
run_test "Boundary: exactly 9" "9 0 +" "9" "success"
run_test "Boundary: exactly 10" "10 0 +" "Error" "error"
run_test "Just over boundary: 11" "11 0 +" "Error" "error"

# Results can exceed 9 (only inputs must be < 10)
run_test "Result > 9 is OK" "9 9 +" "18" "success"
run_test "Large result OK" "9 9 * 9 +" "90" "success"

# Error handling tests for no arguments
echo -e "${YELLOW}Test $((TOTAL_TESTS + 1)): No arguments${NC}"
echo "Expected: Error message (error)"
echo -e "${BLUE}Output:${NC}"
output=$(./RPN 2>&1)
exit_code=$?
TOTAL_TESTS=$((TOTAL_TESTS + 1))
echo "$output"
if [ $exit_code -ne 0 ]; then
    echo -e "${GREEN}✅ PASS${NC}"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}❌ FAIL: Expected error but got success${NC}"
fi
echo
echo "----------------------------------------"
echo

# Error handling tests for multiple arguments
echo -e "${YELLOW}Test $((TOTAL_TESTS + 1)): Multiple arguments${NC}"
echo "Expected: Error message (error)"
echo -e "${BLUE}Output:${NC}"
output=$(./RPN "1 2 +" "3 4 +" 2>&1)
exit_code=$?
TOTAL_TESTS=$((TOTAL_TESTS + 1))
echo "$output"
if [ $exit_code -ne 0 ]; then
    echo -e "${GREEN}✅ PASS${NC}"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}❌ FAIL: Expected error but got success${NC}"
fi
echo
echo "----------------------------------------"
echo

# Summary
echo -e "${BLUE}=== Test Summary ===${NC}"
echo -e "Total tests: ${TOTAL_TESTS}"
echo -e "Passed: ${GREEN}${PASSED_TESTS}${NC}"
echo -e "Failed: ${RED}$((TOTAL_TESTS - PASSED_TESTS))${NC}"
echo -e "Success rate: $(( PASSED_TESTS * 100 / TOTAL_TESTS ))%"

if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
    echo -e "${GREEN}🎉 All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}❌ Some tests failed${NC}"
    exit 1
fi
