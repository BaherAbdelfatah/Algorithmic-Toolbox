#include <iostream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

vector<int> Merge(vector<int> B,vector<int> C,int& merge_counter)
{
	int p=B.size(),q=C.size();
	int d_iterator=0;
	vector<int> D(p+q);
	while((B.size()>0)&&(C.size()>0))
	{
		int b=B[0];
		int c=C[0];
		if(b<=c)
		{
			D[d_iterator++]=b;
			B.erase (B.begin()); 
		}
		else
		{
			for(int i=0;i<B.size();i++)
			{
					if(B[i]>c)
						merge_counter++;
					else
						break;
			}
			D[d_iterator++]=c;
			C.erase (C.begin()); 
		}
	}
	if(B.size()>0)
	{
		for(int i=0;i<B.size();i++)
		{
			D[d_iterator++]=B[i];
		}
	}
	else if(C.size()>0)
	{
		for(int i=0;i<C.size();i++)
		{
			D[d_iterator++]=C[i];
		}
	}
	return D;
}

vector<int> MergeSort(vector<int> a,int low,int high,int &result)
{
	int n=high-low;
	if(low==high)
		return vector<int>(1,a[low]);
	int m=low+n/2;
	vector<int> b = MergeSort(a,low,m,result);
	vector<int> c = MergeSort(a,m+1,high,result);
	vector<int> a_prime = Merge(b,c,result);
	return a_prime;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int merge_count=0;
  vector<int> c=MergeSort(a,0,a.size()-1,merge_count);
  cout<<merge_count;
}
