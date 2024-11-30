#!/bin/bash

for ((i = 0 ; i < 100 ; i++ )); do
    ARG=$(python3 generate_number.py) ; ./push_swap $ARG | ./checker_Mac $ARG;
done