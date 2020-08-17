#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  unsigned int n=a.size(),m=b.size(),l=c.size();
  vector<vector<vector<int>>> D(n+1,vector<vector<int>>(m+1,vector<int>(l+1,0)));
  for(int k=1;k<=l;k++)
  {
	  for(int j=1;j<=m;j++)
	  {
		  unsigned int insertion,deletion,three,match,mismatch;
		  for(int i=1;i<=n;i++)
		  {
			  three=D[i][j][k-1];
			  insertion=D[i][j-1][k];
			  deletion=D[i-1][j][k];

			  match=D[i-1][j-1][k-1]+1;
			  mismatch=D[i-1][j-1][k-1];
			  if(a[i-1]==b[j-1]&&b[j-1]==c[k-1])
				  D[i][j][k]=max(max(insertion,max(deletion,three)),match);
			  else
				  D[i][j][k]=max(max(insertion,max(deletion,three)),mismatch);
		  }
	  }
  }
  return D[n][m][l];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}