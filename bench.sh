#!/bin/bash

SIZE=${1:-100}

# Validate stack size (Max 1000)
if [ "$SIZE" -gt 1000 ]; then
    echo "Error: Maximum stack size allowed is 1000."
    exit 1
fi

LIMIT=$((SIZE * 2))
TESTS=50
S=0

# Check if binary exists
if [ ! -f "./push_swap" ]; then
    echo "Error: ./push_swap not found in this directory."
    exit 1
fi

echo "Running $TESTS tests with stack size $SIZE (Range: -$LIMIT to $LIMIT)...\n"

for i in $(seq 1 $TESTS); do
    ARG=$(seq -$LIMIT $LIMIT | shuf -n $SIZE | tr '\n' ' ')
    L=$(./push_swap $ARG | wc -l)
    echo "Test $i: $L"
    S=$((S+L))
done

echo "-----------------"
echo "Average: $((S/TESTS))"
