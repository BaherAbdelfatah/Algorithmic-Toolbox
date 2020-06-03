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
int gcd_euclid(int a, int b) {
	if(b==0)
		return a;
	else
		return gcd_euclid(b,a%b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_euclid(a, b) << std::endl;
  return 0;
}
