#include <iostream>
#include <vector>
using namespace std;
// The minimum number of coins with denominations 1, 3, 4 that changes money
unsigned int get_change(unsigned int m) {
  //write your code here
	vector<unsigned int> minNumCoins(m+1,10000);
	minNumCoins[0]=0;
	unsigned int coins[3]={1,3,4};
	for(unsigned int i=1;i<=m;i++)
	{
		for(unsigned int j=0;j<3;j++)
		{
			if(i>=coins[j])
			{
				unsigned int numCoins=minNumCoins[i-coins[j]]+1;
				if(numCoins<minNumCoins[i])
					minNumCoins[i]=numCoins;
			}
		}
	}
	return minNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}