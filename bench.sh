#!/bin/bash

N=${1:-50}
S=0

if [ ! -f "./push_swap" ]; then
    echo "Error: ./push_swap not found"
    exit 1
fi

for i in $(seq 1 $N); do
    ARG=$(seq -1000 1000 | shuf -n 500 | tr '\n' ' ')
    L=$(./push_swap $ARG | wc -l)
    echo "Test $i: $L"
    S=$((S+L))
done

echo "Average: $((S/N))"
