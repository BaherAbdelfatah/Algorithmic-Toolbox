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

int findLastDigit(unsigned long long m,unsigned long long n) 
{ 
	unsigned long long f[61] = {0}; 
	fib(f, 60); 
	int result_n=f[n % 60];
	if(result_n==0)
		result_n=10-result_n;
	else
		result_n--;
	int result_m=f[m % 60];
	if(result_m==0)
		result_m=10-result_m;
	else
		result_m--;
	if(result_n-result_m<0)
		return 10+(result_n-result_m);
	else
		return (result_n-result_m); 
} 

int get_fibonacci_partial_sum_fast(unsigned long long from,unsigned long long to) 
{ 
		return findLastDigit(from+1,to+2); 
} 


int main() {
    unsigned long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from,to)<< '\n';
}
