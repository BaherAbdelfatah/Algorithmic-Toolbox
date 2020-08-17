#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

int partition3(vector<int> &A) {
    //write your code here
	vector<int> weights=A;
	int sum=accumulate(A.begin(), A.end(), 0);
	if(sum%3!=0)
		return 0;
	int W[3]={sum/3,sum*2/3,sum};
	int n=weights.size();
	for(int k=0;k<3;k++)
	{
		vector<vector<int>> value(W[k]+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++)
		{
			for(int w=1;w<=W[k];w++)
			{
				int val;
				value[w][i]=value[w][i-1];
				int wi=weights[i-1];
				if(wi<=w)
				{
					val=value[w-wi][i-1]+wi;
					if(value[w][i]<val)
					{
						value[w][i]=val;
					}
				}
			}
		}
		if(value[W[k]][n]!=W[k])
			return 0;
	}
  return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}