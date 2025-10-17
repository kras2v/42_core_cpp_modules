# RPN Calculator Test Cases

## Important Constraint
**The numbers used in this operation and passed as arguments will always be less than 10.**

This means:
- ✅ Valid input numbers: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
- ❌ Invalid input numbers: 10, 11, 12, ..., -1, -2, 1.5, etc.
- ✅ Results can exceed 9 (e.g., 9 + 9 = 18 is valid)

## Test Categories

### 1. VALID SINGLE DIGIT TESTS
```
3 4 +           → 7
9 3 -           → 6  
4 5 *           → 20
8 2 /           → 4
0 5 +           → 5
9 9 +           → 18 (result > 9 is OK)
8 9 * 9 - 9 - 9 - 4 - 1 +  → 42 (subject example)
```

### 2. INVALID NUMBER TESTS (≥ 10)
```
10 5 +          → Error
25 30 +         → Error
100 1 +         → Error
12 3 *          → Error
5 11 -          → Error
```

### 3. INVALID NUMBER TESTS (< 0)
```
-1 2 +          → Error
-5 3 *          → Error
5 -2 +          → Error
```

### 4. INVALID NUMBER TESTS (NON-INTEGER)
```
1.5 2 +         → Error
5.0 3 +         → Error
0.5 1 +         → Error
```

### 5. STRUCTURAL ERROR TESTS
```
5               → Error (missing operator)
5 +             → Error (missing operand)
+               → Error (only operator)
1 2 3 +         → Error (too many operands)
1 + +           → Error (too many operators)
```

### 6. FORMAT ERROR TESTS
```
""              → Error (empty)
"1 2 a +"       → Error (invalid character)
"12+"           → Error (no spaces)
"1  2  +"       → Error (extra spaces)
"+ 1 2"         → Error (wrong order)
```

### 7. BOUNDARY TESTS
```
9 0 +           → 9 (maximum single digit)
0 0 +           → 0 (minimum single digit)
9 9 *           → 81 (largest possible result with single digits)
```

### 8. COMPREHENSIVE SINGLE DIGIT TEST
Test using every single digit in one expression:
```
1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +  → 45
```

## Expected Behavior

### Success Cases:
- Program outputs the calculated result as an integer
- Exit code: 0

### Error Cases:
- Program outputs "Error" 
- Exit code: 1 (or non-zero)

## Key Testing Points:

1. **Input Validation**: Only accept single digits (0-9)
2. **RPN Logic**: Proper postfix evaluation
3. **Operator Support**: +, -, *, /
4. **Error Handling**: Division by zero, malformed input
5. **Format Validation**: Proper spacing and token order
6. **Result Range**: Results can exceed 9, only inputs are constrained
