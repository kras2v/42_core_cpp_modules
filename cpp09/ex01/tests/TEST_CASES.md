# RPN Calculator Test Cases

## Valid Test Cases

### Basic Operations
- `3 4 +` → Expected: 7
- `9 3 -` → Expected: 6  
- `4 5 *` → Expected: 20
- `15 3 /` → Expected: 5

### Complex Expressions
- `8 9 * 9 - 9 - 9 - 4 - 1 +` → Expected: 42 (given example)
- `1 2 + 3 4 + *` → Expected: 21
- `2 3 + 4 5 + *` → Expected: 45
- `1 2 + 3 + 4 + 5 +` → Expected: 15

### Edge Cases
- `0 0 +` → Expected: 0
- `9 9 +` → Expected: 18
- `0 5 +` → Expected: 5
- `0 5 /` → Expected: 0

### Order Dependency
- `5 3 -` → Expected: 2
- `3 5 -` → Expected: -2

## Invalid Test Cases (Should return "Error")

### Division by Zero
- `5 0 /`

### Malformed Expressions
- `42` (single number)
- `+` (single operator)
- `1 2 3 +` (too many numbers)
- `1 + +` (too many operators)
- `1 +` (missing operand)
- `1 2` (missing operator)
- `+ 1 2` (wrong order)

### Invalid Input
- `` (empty expression)
- `1 2 a +` (invalid character)
- `10 20 +` (multi-digit numbers)
- `-1 2 +` (negative numbers)
- `1.5 2 +` (floating point)
- `1  2  +` (extra spaces)
- `12+` (no spaces)

### Program Usage
- No arguments: `./RPN`
- Multiple arguments: `./RPN "1 2 +" "3 4 +"`

## Test Commands

```bash
# Build the program
make

# Run individual tests
./RPN "3 4 +"                    # Should output: 7
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" # Should output: 42
./RPN "5 0 /"                    # Should output: Error
./RPN "10 20 +"                  # Should output: Error

# Run comprehensive test suite
./test_rpn.sh
```

## Expected Behavior

- Valid RPN expressions should output the calculated result
- Invalid expressions should output "Error" and exit with non-zero code
- The program should only accept single-digit numbers (0-9)
- Operations are: +, -, *, /
- Division by zero should be handled gracefully
- Arguments must be space-separated
- Program should take exactly one argument
