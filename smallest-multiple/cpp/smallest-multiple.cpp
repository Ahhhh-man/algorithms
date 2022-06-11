#include<iostream>
using namespace std;

/*

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

bool divisionCheck(int num)
{
  for (size_t i = 2; i <= 20; i++) if (num % i != 0) return false;
  return true;
}


int smallestNumber() {
  bool smallest = false;
  int counter = 2*2*2*2*3*3*5*7*11*13*17*19 ;                                   // speed up calculations since by prime factorisation (a=p_1*P_2*...*p_n for some p_i in {2,2,2,2,3,3,5,7,11,13,17,19})
  std::cout << counter << '\n';
  while (smallest == false) {
    if (divisionCheck(counter))
    {
      smallest = true;
      break;
    }
    counter+=2;                                                                 // counter starts off odd, hence odd + 2 = odd (skip all even numbers to reduce time)
  }
  return counter;
}


int main() {
  std::cout << smallestNumber() << '\n';
  return 0;
}

// Note 2520 = 2*2*2*3*3*5*7 so make code better!! and 232792560 = 2*2*2*2*3*3*5*7*11*13*17*19