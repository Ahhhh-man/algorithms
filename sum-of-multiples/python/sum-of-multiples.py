"""

Problem 1 - Multiples of 3 and 5 [https://projecteuler.net/problem=1]

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these
multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.

"""

import math


class SumFactors:
    def __init__(self, upper_bound):
        self.upper_bound = upper_bound
        print(self.compute())

    def sum_of_multiples(self, num):
        # if 3 is a factor of 0 < x < 1000, say x = 3y, then y < 1000/3
        return sum(num * i for i in range(math.ceil(self.upper_bound / num)))
    
    def compute(self):
        # Inclusion–exclusion principle
        return self.sum_of_multiples(3) + self.sum_of_multiples(5) - self.sum_of_multiples(15)


if __name__ == "__main__":
    SumFactors(10)  # 23 by example
    SumFactors(1_000)  # 233168 (my answer) Ran 1 test in 0.002s
