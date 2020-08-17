#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  unsigned int n=a.size(),m=b.size();
  vector<vector<int>> D(n+1,vector<int>(m+1,0));
  for(int j=1;j<=m;j++)
  {
	  unsigned int insertion,deletion,match,mismatch;
	  for(int i=1;i<=n;i++)
	  {
		  insertion=D[i][j-1];
		  deletion=D[i-1][j];
		  match=D[i-1][j-1]+1;
		  mismatch=D[i-1][j-1];
		  if(a[i-1]==b[j-1])
			  D[i][j]=max(max(insertion,deletion),match);
		  else
			  D[i][j]=max(max(insertion,deletion),mismatch);
	  }
  }
  return D[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}