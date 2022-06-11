"""

Problem 1 - Multiples of 3 and 5 [https://projecteuler.net/problem=1]

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these
multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.

"""

# Remark: Modern computers can brute force this quickly, hence simply loop from 0 to 1000.

def sum_of_factors(upper_bound, factors):
    # sum all the numbers that are have remainder zero for some factor in factor set
    return sum(num for num in range(upper_bound) if 0 in (num % div for div in factors))


print(sum_of_factors(1000, {3, 5}))  # for factors set = {3, 5}
