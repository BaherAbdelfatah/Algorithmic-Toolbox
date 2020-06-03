#include <iostream>
#include <bits/stdc++.h> 
#include<math.h> 
#include<cmath> 
#include <sstream>
using namespace std; 

unsigned long long fib(unsigned long long f[], unsigned long long n) 
{ 
	f[0] = 0; 
	f[1] = 1; 

	for (unsigned long long i = 2; i <= n; i++) 
		f[i] = (f[i - 1] + f[i - 2]) % 10; 

	return f[n]; 
} 

int findLastDigit(unsigned long long n) 
{ 
	unsigned long long f[61] = {0}; 
	fib(f, 60); 
	return f[n % 60]; 
} 

int fibonacci_sum_fast(unsigned long long n) 
{ 
	int result=findLastDigit(n)*findLastDigit(n+1);
	return result%10; 
} 


int main() {
    unsigned long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
