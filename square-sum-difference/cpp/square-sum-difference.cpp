#include<iostream>

using namespace std;

/*

The sum of the squares of the first ten natural numbers is 385,
The square of the sum of the first ten natural numbers is 3025,
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

int squareSum(int num) {
  int sum = 0;
  for (size_t i = 1; i <= num; i++) sum += i * i;
  return sum;
}


int sumSquare(int num) {
  int sum = 0;
  for (size_t i = 1; i <= num; i++) sum += i;
  return sum * sum;
}


int main() {
  for (size_t i = 1; i < 100; i++) std::cout << sumSquare(i) - squareSum(i) << '\n'; // squareSum <=  sumSquare so abs() not needed

  return 0;
}