#!/bin/bash

all_successful=true
min_operations=1000000
max_operations=0
min_case=""
max_case=""

for ((i = 0 ; i < 100 ; i++ )); do
    ARG=$(python3 generate_number.py)
    
    OPERATIONS=$(./push_swap $ARG | tee result.txt | wc -l | tr -d ' ')
    RESULT=$(./push_swap $ARG | ./checker_Mac $ARG)

    if [ "$RESULT" == "OK" ]; then
        echo "Test $i: OK ($OPERATIONS operations)"

        if (( OPERATIONS < min_operations )); then
            min_operations=$OPERATIONS
            min_case=$ARG
        fi

        if (( OPERATIONS > max_operations )); then
            max_operations=$OPERATIONS
            max_case=$ARG
        fi
    else
        echo "Test $i: Failed case: $ARG"
        echo "Checker output: $RESULT"
        echo "Operations performed: $(cat result.txt)"
        all_successful=false
    fi

done

if $all_successful; then
    echo -e "\033[95mAll tests are successful! 🎉\033[0m"
else
    echo -e "\033[94mOne or more tests failed. ❌\033[0m"
fi

echo -e "\033[92mMinimum operations: $min_operations\033[0m"
echo -e "\033[94mMaximum operations: $max_operations\033[0m"

