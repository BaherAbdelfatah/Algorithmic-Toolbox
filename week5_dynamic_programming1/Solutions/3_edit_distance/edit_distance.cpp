#include <iostream>
#include <string>
#include <vector>
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  unsigned int n=str1.length(),m=str2.length();
  vector<vector<int>> D(n+1,vector<int>(m+1,0));
  for(int i=0,j=0;i<=n;i++)
	  D[i][j]=i;
  for(int i=0,j=0;j<=m;j++)
	  D[i][j]=j;
  for(int j=1;j<=m;j++)
  {
	  unsigned int insertion,deletion,match,mismatch;
	  for(int i=1;i<=n;i++)
	  {
		  insertion=D[i][j-1]+1;
		  deletion=D[i-1][j]+1;
		  match=D[i-1][j-1];
		  mismatch=D[i-1][j-1]+1;
		  if(str1[i-1]==str2[j-1])
			  D[i][j]=min(min(insertion,deletion),match);
		  else
			  D[i][j]=min(min(insertion,deletion),mismatch);
	  }
  }
  return D[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}