#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/04/30 13:00:00 by jagan            #+#    #+#              #
#    Updated: 2026/04/30 14:00:00 by jagan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

print_header() {
    echo -e "\n${BLUE}========================================${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}========================================${NC}\n"
}

print_result() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}✓ PASS${NC}: $2"
        ((PASSED_TESTS++))
    else
        echo -e "${RED}✗ FAIL${NC}: $2"
        ((FAILED_TESTS++))
    fi
    ((TOTAL_TESTS++))
}

print_summary() {
    echo -e "\n${BLUE}========================================${NC}"
    echo -e "${BLUE}TEST SUMMARY${NC}"
    echo -e "${BLUE}========================================${NC}"
    echo -e "Total Tests: ${YELLOW}$TOTAL_TESTS${NC}"
    echo -e "Passed: ${GREEN}$PASSED_TESTS${NC}"
    echo -e "Failed: ${RED}$FAILED_TESTS${NC}"
    echo -e "${BLUE}========================================${NC}\n"
}

print_header "BUILDING EXECUTABLES"

make fclean > /dev/null 2>&1
make > /dev/null 2>&1
if [ -f push_swap ]; then
    echo -e "${GREEN}✓${NC} push_swap compiled successfully"
else
    echo -e "${RED}✗${NC} push_swap compilation failed"
    exit 1
fi

make bonus > /dev/null 2>&1
if [ -f checker ]; then
    echo -e "${GREEN}✓${NC} checker compiled successfully"
else
    echo -e "${RED}✗${NC} checker compilation failed"
    exit 1
fi

print_header "PUSH_SWAP TESTS"

echo "Test 1: No arguments (should output nothing)"
OUTPUT=$(./push_swap 2>&1)
if [ -z "$OUTPUT" ]; then
    print_result 0 "No arguments - outputs nothing"
else
    print_result 1 "No arguments - should output nothing, got: $OUTPUT"
fi

echo "Test 2: Single element (should output nothing)"
OUTPUT=$(./push_swap 42 2>&1)
if [ -z "$OUTPUT" ]; then
    print_result 0 "Single element - outputs nothing"
else
    print_result 1 "Single element - should output nothing, got: $OUTPUT"
fi

echo "Test 3: Already sorted (1 2)"
OUTPUT=$(./push_swap 1 2 2>&1)
if [ -z "$OUTPUT" ]; then
    print_result 0 "Already sorted 2 elements - outputs nothing"
else
    print_result 1 "Already sorted 2 elements - should output nothing"
fi

echo "Test 4: Reverse sorted (2 1)"
OUTPUT=$(./push_swap 2 1 2>&1)
if echo "$OUTPUT" | grep -q "^sa$"; then
    print_result 0 "Reverse sorted 2 elements - outputs sa"
else
    print_result 1 "Reverse sorted 2 elements - should output sa"
fi

echo "Test 5: Already sorted (1 2 3)"
OUTPUT=$(./push_swap 1 2 3 2>&1)
if [ -z "$OUTPUT" ]; then
    print_result 0 "Already sorted 3 elements - outputs nothing"
else
    print_result 1 "Already sorted 3 elements - should output nothing"
fi

echo "Test 6: Three elements (3 2 1)"
OUTPUT=$(./push_swap 3 2 1 2>&1)
COUNT=$(echo "$OUTPUT" | sed '/^\s*$/d' | wc -l)
if [ "$COUNT" -le 3 ]; then
    print_result 0 "Three elements - $COUNT operations (≤ 3)"
else
    print_result 1 "Three elements - $COUNT operations (should be ≤ 3)"
fi

echo "Test 7: Invalid integer (3 2 one)"
OUTPUT=$(./push_swap 3 2 one 2>&1)
if echo "$OUTPUT" | grep -q "Error"; then
    print_result 0 "Invalid integer - outputs Error"
else
    print_result 1 "Invalid integer - should output Error"
fi

echo "Test 8: Integer overflow (2147483648)"
OUTPUT=$(./push_swap 2147483648 2>&1)
if echo "$OUTPUT" | grep -q "Error"; then
    print_result 0 "Integer overflow - outputs Error"
else
    print_result 1 "Integer overflow - should output Error"
fi

echo "Test 9: Negative integer overflow (-2147483649)"
OUTPUT=$(./push_swap -2147483649 2>&1)
if echo "$OUTPUT" | grep -q "Error"; then
    print_result 0 "Negative overflow - outputs Error"
else
    print_result 1 "Negative overflow - should output Error"
fi

echo "Test 10: Duplicate values (1 2 2 3)"
OUTPUT=$(./push_swap 1 2 2 3 2>&1)
if echo "$OUTPUT" | grep -q "Error"; then
    print_result 0 "Duplicates - outputs Error"
else
    print_result 1 "Duplicates - should output Error"
fi

echo "Test 11: Negative numbers (-3 -1 -2)"
OUTPUT=$(./push_swap -3 -1 -2 2>&1)
COUNT=$(echo "$OUTPUT" | sed '/^\s*$/d' | wc -l)
if [ "$COUNT" -gt 0 ] && [ "$COUNT" -le 3 ]; then
    print_result 0 "Negative numbers - $COUNT operations (≤ 3)"
else
    print_result 1 "Negative numbers - invalid operation count"
fi

echo "Test 12: Mixed (5 -3 0 2 -1)"
OUTPUT=$(./push_swap 5 -3 0 2 -1 2>&1)
COUNT=$(echo "$OUTPUT" | sed '/^\s*$/d' | wc -l)
if [ "$COUNT" -gt 0 ]; then
    print_result 0 "Mixed numbers - $COUNT operations"
else
    print_result 1 "Mixed numbers - no output"
fi

echo "Test 13: Five elements (5 4 3 2 1)"
OUTPUT=$(./push_swap 5 4 3 2 1 2>&1)
COUNT=$(echo "$OUTPUT" | sed '/^\s*$/d' | wc -l)
if [ "$COUNT" -le 12 ]; then
    print_result 0 "Five elements - $COUNT operations (≤ 12)"
else
    print_result 1 "Five elements - $COUNT operations (should be ≤ 12)"
fi

echo "Test 14: 100 random numbers (benchmark)"
ARG="$(shuf -i 1-100 -n 100 | tr '\n' ' ')"
OUTPUT=$(./push_swap $ARG 2>&1)
COUNT=$(echo "$OUTPUT" | sed '/^\s*$/d' | wc -l)
if [ "$COUNT" -lt 700 ]; then
    print_result 0 "100 numbers - $COUNT operations (< 700)"
else
    print_result 1 "100 numbers - $COUNT operations (should be < 700)"
fi

print_header "CHECKER TESTS"

echo "Test 1: No arguments (should output nothing)"
OUTPUT=$(echo "" | ./checker 2>&1)
if [ -z "$OUTPUT" ]; then
    print_result 0 "No arguments - outputs nothing"
else
    print_result 1 "No arguments - should output nothing"
fi

echo "Test 2: Single element with no operations"
OUTPUT=$(echo "" | ./checker 42 2>&1)
if echo "$OUTPUT" | grep -q "OK"; then
    print_result 0 "Single element - outputs OK"
else
    print_result 1 "Single element - should output OK"
fi

echo "Test 3: Already sorted (1 2 3) with no operations"
OUTPUT=$(echo "" | ./checker 1 2 3 2>&1)
if echo "$OUTPUT" | grep -q "OK"; then
    print_result 0 "Already sorted - outputs OK"
else
    print_result 1 "Already sorted - should output OK"
fi

echo "Test 4: (2 1) with sa operation"
OUTPUT=$(echo -e "sa" | ./checker 2 1 2>&1)
if echo "$OUTPUT" | grep -q "OK"; then
    print_result 0 "Swap operation - outputs OK"
else
    print_result 1 "Swap operation - should output OK"
fi

echo "Test 5: (2 1) with wrong operation (pa)"
OUTPUT=$(echo -e "pa" | ./checker 2 1 2>&1)
if echo "$OUTPUT" | grep -q "KO"; then
    print_result 0 "Wrong operation - outputs KO"
else
    print_result 1 "Wrong operation - should output KO"
fi

echo "Test 6: Invalid operation (invalid_op)"
OUTPUT=$(echo -e "invalid_op" | ./checker 3 2 1 2>&1)
if echo "$OUTPUT" | grep -q "Error"; then
    print_result 0 "Invalid operation - outputs Error"
else
    print_result 1 "Invalid operation - should output Error"
fi

echo "Test 7: Duplicate values (1 2 2 3)"
OUTPUT=$(./checker 1 2 2 3 2>&1)
if echo "$OUTPUT" | grep -q "Error"; then
    print_result 0 "Duplicates - outputs Error"
else
    print_result 1 "Duplicates - should output Error"
fi

echo "Test 8: Invalid integer (3 2 one)"
OUTPUT=$(./checker 3 2 one 2>&1)
if echo "$OUTPUT" | grep -q "Error"; then
    print_result 0 "Invalid integer - outputs Error"
else
    print_result 1 "Invalid integer - should output Error"
fi

echo "Test 9: Complex valid sequence"
OUTPUT=$(echo -e "rra\npb\nsa\nrra\npa" | ./checker 3 2 1 0 2>&1)
if echo "$OUTPUT" | grep -q "OK"; then
    print_result 0 "Complex sequence - outputs OK"
else
    print_result 1 "Complex sequence - should output OK"
fi

echo "Test 10: Stack b not empty at end"
OUTPUT=$(echo -e "pb" | ./checker 2 1 2>&1)
if echo "$OUTPUT" | grep -q "KO"; then
    print_result 0 "Stack b not empty - outputs KO"
else
    print_result 1 "Stack b not empty - should output KO"
fi

echo "Test 11: Checker produces NO extra output (critical regression test)"
OUTPUT=$(echo -e "sa" | ./checker 2 1 2>&1)
LINE_COUNT=$(echo "$OUTPUT" | wc -l)
if [ "$LINE_COUNT" -eq 1 ] && echo "$OUTPUT" | grep -q "OK"; then
    print_result 0 "Checker outputs exactly one line (OK) - no operation echoing"
else
    print_result 1 "Checker outputting extra lines: $OUTPUT"
fi

print_header "INTEGRATION TESTS (push_swap + checker)"

echo "Test 1: Small set (5 4 3 2 1)"
ARG="5 4 3 2 1"
OUTPUT=$(./push_swap $ARG | ./checker $ARG 2>&1)
if echo "$OUTPUT" | grep -q "OK"; then
    print_result 0 "Small set - push_swap + checker = OK"
else
    print_result 1 "Small set - integration failed: $OUTPUT"
fi

echo "Test 2: Medium set (10 elements)"
ARG="10 9 8 7 6 5 4 3 2 1"
OUTPUT=$(./push_swap $ARG | ./checker $ARG 2>&1)
if echo "$OUTPUT" | grep -q "OK"; then
    print_result 0 "Medium set - push_swap + checker = OK"
else
    print_result 1 "Medium set - integration failed: $OUTPUT"
fi

echo "Test 3: Random 50 elements"
ARG="$(shuf -i 1-50 -n 50 | tr '\n' ' ')"
OUTPUT=$(./push_swap $ARG | ./checker $ARG 2>&1)
if echo "$OUTPUT" | grep -q "OK"; then
    print_result 0 "Random 50 - push_swap + checker = OK"
else
    print_result 1 "Random 50 - integration failed: $OUTPUT"
fi

echo "Test 4: Negative numbers (-5 -1 -3 0 2)"
ARG="-5 -1 -3 0 2"
OUTPUT=$(./push_swap $ARG | ./checker $ARG 2>&1)
if echo "$OUTPUT" | grep -q "OK"; then
    print_result 0 "Negative numbers - push_swap + checker = OK"
else
    print_result 1 "Negative numbers - integration failed: $OUTPUT"
fi

echo "Test 5: Already sorted (1 2 3 4 5)"
ARG="1 2 3 4 5"
OUTPUT=$(./push_swap $ARG | ./checker $ARG 2>&1)
if echo "$OUTPUT" | grep -q "OK"; then
    print_result 0 "Already sorted - push_swap + checker = OK"
else
    print_result 1 "Already sorted - integration failed: $OUTPUT"
fi

print_header "PERFORMANCE TESTS (Benchmarks)"

echo "Test 1: 100 random numbers (5 runs average)"
TOTAL_OPS=0
for i in {1..5}; do
    ARG="$(shuf -i 1-100 -n 100 | tr '\n' ' ')"
    COUNT=$(./push_swap $ARG | wc -l)
    TOTAL_OPS=$((TOTAL_OPS + COUNT))
    echo "  Run $i: $COUNT operations"
done
AVG=$((TOTAL_OPS / 5))
if [ "$AVG" -lt 700 ]; then
    print_result 0 "100 numbers - Average: $AVG operations (< 700)"
else
    print_result 1 "100 numbers - Average: $AVG operations (should be < 700)"
fi

echo "Test 2: 500 random numbers (1 run)"
ARG="$(shuf -i 1-500 -n 500 | tr '\n' ' ')"
COUNT=$(./push_swap $ARG | wc -l)
if [ "$COUNT" -le 5500 ]; then
    print_result 0 "500 numbers - $COUNT operations (≤ 5500)"
else
    print_result 1 "500 numbers - $COUNT operations (should be ≤ 5500)"
fi

print_summary

if [ $FAILED_TESTS -gt 0 ]; then
    exit 1
else
    exit 0
fi