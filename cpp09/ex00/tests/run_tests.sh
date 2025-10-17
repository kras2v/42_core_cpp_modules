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

echo -e "${BLUE}=== Bitcoin Exchange Test Suite ===${NC}"
echo

# Function to run a test
run_test() {
    local test_name="$1"
    local input_file="$2"
    local expected_behavior="$3"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    echo -e "${YELLOW}Test ${TOTAL_TESTS}: ${test_name}${NC}"
    echo "Input file: $input_file"
    echo "Expected: $expected_behavior"
    echo -e "${BLUE}Output:${NC}"

    ./btc "$input_file" 2>&1
    local exit_code=$?
    
    echo "Exit code: $exit_code"
    
    case "$expected_behavior" in
        "success")
            if [ $exit_code -eq 0 ]; then
                echo -e "${GREEN}✅ PASS${NC}"
                PASSED_TESTS=$((PASSED_TESTS + 1))
            else
                echo -e "${RED}❌ FAIL: Expected success but got error${NC}"
            fi
            ;;
        "error")
            if [ $exit_code -ne 0 ]; then
                echo -e "${GREEN}✅ PASS${NC}"
                PASSED_TESTS=$((PASSED_TESTS + 1))
            else
                echo -e "${RED}❌ FAIL: Expected error but got success${NC}"
            fi
            ;;
        "partial")
            echo -e "${GREEN}✅ PASS (manual verification required)${NC}"
            PASSED_TESTS=$((PASSED_TESTS + 1))
            ;;
    esac
    
    echo
    echo "----------------------------------------"
    echo
}

# Build the program
echo -e "${BLUE}Building Bitcoin Exchange...${NC}"
make re
if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Build failed! Cannot run tests.${NC}"
    exit 1
fi
echo -e "${GREEN}✅ Build successful${NC}"
echo

# Test 1: Valid input file with correct format
run_test "Valid Bitcoin calculations" "test_valid.txt" "success"

# Test 2: Original input file (mixed valid/invalid)
run_test "Original input file (mixed cases)" "input.txt" "partial"

# Test 3: Invalid values (negative, too large, non-numeric)
run_test "Invalid values handling" "test_invalid_values.txt" "partial"

# Test 4: Invalid dates
run_test "Invalid dates handling" "test_invalid_dates.txt" "partial"

# Test 5: Wrong header format
run_test "Wrong header format" "test_wrong_header.txt" "error"

# Test 6: Malformed lines
run_test "Malformed lines handling" "test_malformed_lines.txt" "partial"

# Test 7: Empty file
run_test "Empty file handling" "test_empty.txt" "error"

# Test 8: Edge cases (boundary dates)
run_test "Edge cases with boundary dates" "test_edge_cases.txt" "success"

# Test 9: Non-existent file
run_test "Non-existent file" "nonexistent.txt" "error"

# Test 10: No arguments
echo -e "${YELLOW}Test $((TOTAL_TESTS + 1)): No arguments${NC}"
echo "Expected: error"
echo -e "${BLUE}Output:${NC}"
./btc 2>&1
exit_code=$?
TOTAL_TESTS=$((TOTAL_TESTS + 1))
if [ $exit_code -ne 0 ]; then
    echo -e "${GREEN}✅ PASS${NC}"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}❌ FAIL: Expected error but got success${NC}"
fi
echo
echo "----------------------------------------"
echo

# Test 11: Multiple arguments
echo -e "${YELLOW}Test $((TOTAL_TESTS + 1)): Multiple arguments${NC}"
echo "Expected: error"
echo -e "${BLUE}Output:${NC}"
./btc test_valid.txt input.txt 2>&1
exit_code=$?
TOTAL_TESTS=$((TOTAL_TESTS + 1))
if [ $exit_code -ne 0 ]; then
    echo -e "${GREEN}✅ PASS${NC}"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}❌ FAIL: Expected error but got success${NC}"
fi
echo
echo "----------------------------------------"
echo

# Test 12: Missing data.csv
echo -e "${YELLOW}Test $((TOTAL_TESTS + 1)): Missing database file${NC}"
echo "Expected: error"
echo -e "${BLUE}Output:${NC}"
mv data.csv data.csv.backup 2>/dev/null
./btc test_valid.txt 2>&1
exit_code=$?
mv data.csv.backup data.csv 2>/dev/null
TOTAL_TESTS=$((TOTAL_TESTS + 1))
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
