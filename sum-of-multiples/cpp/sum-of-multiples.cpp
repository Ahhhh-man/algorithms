#include <iostream>

using namespace std;

int sumOfMultiples(int num, int upperBound) {
  int sum = 0;
  for (size_t i = 0; i <= (upperBound - 1) / num; i++)
    sum += num * i; // Remark: Below 1000 implies minus 1
  return sum;
}

int inclusionExclusionSum(int upperBound, int num1, int num2) {
  return sumOfMultiples(num1, upperBound) + sumOfMultiples(num2, upperBound) -
    sumOfMultiples(num1 * num2, upperBound);
}

int main() {
  cout << inclusionExclusionSum(1000, 3, 5) << endl;
  return 0;
}