#include<iostream>
#include<string>
using namespace std;
/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
bool palidromCheck(long int num){
  string str = to_string(num);
  for (size_t i = 0; i < str.length()/2; i++) if (str[i]!=str[str.length()-1-i]) return false;
  return true;
}

int largestPalidrome(){
  int largest = 0;
  for (size_t i = 999; i > 0; i--) for (size_t j = 999; j > 0; j--) if (palidromCheck(i*j) && largest < i*j)  largest = i*j;
  return largest;
}

int main(){
  std::cout << largestPalidrome() << '\n';
  return 0;
}
