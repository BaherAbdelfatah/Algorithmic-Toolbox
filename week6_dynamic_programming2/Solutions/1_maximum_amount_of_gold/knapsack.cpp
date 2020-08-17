#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &weights) {
  //write your code here
	int n=weights.size();
	vector<vector<int>> value(W+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int w=1;w<=W;w++)
		{
			int val;
			value[w][i]=value[w][i-1];
			int wi=weights[i-1];
			if(wi<=w)
			{
				val=value[w-wi][i-1]+wi;
				if(value[w][i]<val)
					value[w][i]=val;
			}
		}
	}
	return value[W][n];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}