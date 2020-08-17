#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;
long long M[15][15];
long long m[15][15];
vector<char> operators;
vector<long long> d;
long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}
void MinAndMax(long long i,long long j)
{
	long long mini = 100000000;
	long long maxi = -100000000;
	long long a,b,c,d;
	for(int k=i;k<=j-1;k++)
	{
		a=eval(M[i][k],M[k+1][j],operators[k]);
		b=eval(M[i][k],m[k+1][j],operators[k]);
		c=eval(m[i][k],M[k+1][j],operators[k]);
		d=eval(m[i][k],m[k+1][j],operators[k]);
		mini=min(min(min(min(mini,a),b),c),d);
		maxi=max(max(max(max(maxi,a),b),c),d);
		m[i][j]=mini;
		M[i][j]=maxi;
	}
}
long long get_maximum_value(const string &exp) {
  //write your code here
	if(exp.length()==1)
		return stoi(exp);

	for(int i=1;i<exp.length();i+=2)
	{
		operators.push_back(exp[i]);
	}
	for(int i=0;i<exp.length();i+=2)
	{
		d.push_back(exp[i]-48);
	}

	for(int i=0;i<d.size();i++)
	{
		m[i][i]=d[i];
		M[i][i]=d[i];
	}
	int n=d.size();
	for(int s=0;s<=n-1;s++)
	{
		for(int i=0;i<n-s;i++)
		{
			int j=i+s;
			MinAndMax(i,j);
		}
	}
	return M[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}