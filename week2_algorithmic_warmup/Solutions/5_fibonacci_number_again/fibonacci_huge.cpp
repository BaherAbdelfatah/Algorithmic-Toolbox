#include <iostream>
#include <vector>
using namespace std;
/*
def pisanoPeriod(m): 
    previous, current = 0, 1
    for i in range(0, m * m): 
        previous, current \ = current, (previous + current) % m 
          
        # A Pisano Period starts with 01 
        if (previous == 0 and current == 1): 
            return i + 1
*/
unsigned long long get_pisano_period(unsigned long long m) {
    unsigned long long a = 0, b = 1, c = a + b;
    for (unsigned long long i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

unsigned long long fibonacci_fast(unsigned long long n, unsigned long long m) {
    // write your code here
	unsigned long long pisano_period=get_pisano_period(m);
	vector<unsigned long long> fib(pisano_period,0);
	fib[0]=0;
	fib[1]=1;
	for(unsigned long long i=2;i<pisano_period;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		fib[i]%=m;
	}
    return fib[n%(pisano_period)];
}


int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    std::cout << fibonacci_fast(n, m) << '\n';
}
