#!/bin/bash

# Problem:
# Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2,
# the first 10 terms will be: 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ... By considering the terms in the Fibonacci
# sequence whose values do not exceed four million, find the sum of the even-valued terms.


# Solution:

# Declare variables
declare -i first=1
declare -i second=1
declare -i current
declare -i sum=0

# # While the current Fibonacci number is less than 4,000,000
while [[ $current -lt 4000000 ]]
do
    # Add the current Fibonacci number to the sum if it is even
    if [[ $((current%2)) -eq 0 ]]
    then
        sum=$((sum + current))
    fi
    # Calculate the next Fibonacci number
    current=$((first + second))

    # Update the first and second Fibonacci numbers
    first=$second
    second=$current
done

# Print the sum
echo $sum
exit 0