# Bitcoin Exchange Test Suite

This directory contains comprehensive tests for the BitcoinExchange program.

## Overview

The BitcoinExchange program calculates the value of Bitcoin amounts on specific dates using a CSV database of historical prices.

## Test Files

### Database File
- `data.csv` - Contains historical Bitcoin exchange rates in format: `date,exchange_rate`

### Input Test Files
1. **`input.txt`** - Original example file with mixed valid/invalid entries
2. **`test_valid.txt`** - Valid entries that should process successfully
3. **`test_invalid_values.txt`** - Tests value validation (negative, too large, non-numeric)
4. **`test_invalid_dates.txt`** - Tests date validation (invalid formats, out of range)
5. **`test_wrong_header.txt`** - Tests header format validation
6. **`test_malformed_lines.txt`** - Tests malformed line handling
7. **`test_empty.txt`** - Empty file test
8. **`test_edge_cases.txt`** - Boundary date testing

## Test Programs

### Integration Tests (`run_tests.sh`)
Comprehensive bash script that tests:
- Valid Bitcoin calculations
- Error handling for various input types
- File format validation
- Command line argument validation
- Missing file handling

**Usage:**
```bash
make
./run_tests.sh
```

### Unit Tests (`test_unit.cpp`)
C++ unit tests for individual components:
- Constructor validation
- File validation
- Date parsing
- Value parsing
- Exception handling

**Usage:**
```bash
make test
./test_unit
```

### Combined Test Runner
Run all tests with:
```bash
make run_tests
```

## Expected Program Behavior

### Valid Input Format
```
date | value
YYYY-MM-DD | amount
```

### Output Format
```
YYYY-MM-DD => amount = result
```

### Error Messages
- `Error: bad input => [line]` - Invalid line format
- `Error: not a positive number.` - Negative values
- `Error: too large a number.` - Values > 1000
- `Error: could not open file.` - File access issues
- `Error: bad input (date before first record) => [date]` - Date before database range

## Test Categories

### ✅ Valid Cases
- Proper date/value format
- Values within range (0-1000)
- Dates within database range

### ❌ Invalid Values
- Negative numbers
- Values > 1000
- Non-numeric values
- Missing values

### ❌ Invalid Dates
- Malformed date strings
- Dates before database range
- Invalid calendar dates

### ❌ Format Errors
- Wrong header format
- Missing separators
- Lines too short/long

## Database Coverage

The test database (`data.csv`) covers:
- Early Bitcoin history (2009-2011)
- Growth period (2013-2017)
- Recent values (2021-2024)
- Edge cases (zero values, high values)

## Running Tests

1. **Build the program:**
   ```bash
   make
   ```

2. **Run integration tests:**
   ```bash
   ./run_tests.sh
   ```

3. **Run unit tests:**
   ```bash
   make test
   ./test_unit
   ```

4. **Run all tests:**
   ```bash
   make run_tests
   ```

## Test Output

Tests provide colored output:
- 🟢 Green: Passed tests
- 🔴 Red: Failed tests
- 🟡 Yellow: Test names/info
- 🔵 Blue: Section headers

## Expected Results

All tests should pass if the BitcoinExchange implementation correctly:
- Validates file formats and headers
- Parses dates and values properly
- Handles edge cases and errors gracefully
- Calculates Bitcoin values accurately
- Provides appropriate error messages
