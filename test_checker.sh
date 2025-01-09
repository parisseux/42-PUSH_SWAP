#!/bin/bash

all_successful=true # 

for ((i = 0 ; i < 100 ; i++ )); do
    ARG=$(python3 generate_number.py)
    OPERATIONS=$(./push_swap $ARG | tee result.txt | wc -l | tr -d ' ')
    RESULT=$(./push_swap $ARG | ./checker_Mac $ARG)
    if [ "$RESULT" == "OK" ]; then
        echo "Test $i: OK ($OPERATIONS operations)"
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