#include <iostream>
/*
Euclid(a,b) {
  while (b not 0) { 
    interchange(a,b)
    b := b mod a
  }
  return(a)
}
*/
unsigned long long gcd_euclid(unsigned long long a, unsigned long long b) {
	if(b==0)
		return a;
	else
		return gcd_euclid(b,a%b);
}

unsigned long long lcm_naive(unsigned long long a, unsigned long long b) {
  return (a*b)/gcd_euclid(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
