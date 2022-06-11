#include<iostream>
using namespace std;

int powmod2(int x,int y, int m) {
  if(y<=0) return 1;
  return x*powmod2(x,y-1,m) %m;
}

int powmod3(int x,int y, int m) {
  if(y<=0) return 1;
  int z=powmod3(x,y/2,m);
  if (y%2==0) {
    return z*z % m;
  } else {
    return x*z*z % m;
  }
}

int powmod3loop(int x,int y, int m) {
  int ans = 1 % m;
  for (size_t i = 0; i < y/2; i++) {
    ans = (ans * x)%m;
  }
  if (y%2==0) {
    return ans*ans % m;
  } else {
    return x*ans*ans % m;
  }
}

int powmod3cbr(int x, int y, int m, int& ans) {
  if (x<0 || y<0 || m<=0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int x,y,m;
  std::cout << "What's the Base number? [int x] " << '\n';
  std::cin >> x;
  std::cout << "What's the power number? [int y] " << '\n';
  std::cin >> y;
  std::cout << "What's the modulo number? [int m] " << '\n';
  std::cin >> m;
  int p = powmod3(x,y,m);
  if (powmod3cbr(x,y,m,p) != 0) {
      std::cout << "An error occurred" << '\n';
  } else {
      std::cout << "Calculating " << x << "^" << y << " mod " << m << '\n';
      std::cout << "powmod2: " << powmod2(x,y,m) << '\n';
      std::cout << "powmod3: " << powmod3(x,y,m) << '\n';
      std::cout << "powmod3loop: " << powmod3loop(x,y,m) << '\n';
      std::cout << "powmod3cbr: " << p << '\n';
  }
  return 0;
}
