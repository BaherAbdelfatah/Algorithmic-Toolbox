#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}
*/
// +1 *2 *3
vector<unsigned long long> optimal_sequence(unsigned long long m) {
  //write your code here
	vector<unsigned long long> minNumOperations(m+1,10000000);
	vector<vector<unsigned long long>> Operations(m+1),Operations_temp1(m+1),Operations_temp2(m+1),Operations_temp3(m+1);
	minNumOperations[0]=0;
	for(unsigned long long i=1;i<=m;i++)
	{
		long long numOperations1=-1,numOperations2=-1,numOperations3=-1;
		for(unsigned long long j=0;j<3;j++)
		{		
			switch(j) {
			   case 0 :
				  numOperations1=minNumOperations[i-1]+1;
				  Operations_temp1[i]=Operations[i-1];
				  Operations_temp1[i].push_back(i);
				  break; 
			   case 1  :
				  if(i%2==0)
				  {
					numOperations2=minNumOperations[i/2]+1;
					Operations_temp2[i]=Operations[i/2];
					Operations_temp2[i].push_back(i);
				  }
				  break; 
			  case 2  :
				  if(i%3==0)
				  {
					numOperations3=minNumOperations[i/3]+1;
					Operations_temp3[i]=Operations[i/3];
					Operations_temp3[i].push_back(i);
				  }
				  break; 
			}
				if(numOperations1<minNumOperations[i]&&numOperations1!=-1)
				{
					minNumOperations[i]=numOperations1;
					Operations[i]=Operations_temp1[i];
				}
				else if(numOperations2<minNumOperations[i]&&numOperations2!=-1)
				{
					minNumOperations[i]=numOperations2;
					Operations[i]=Operations_temp2[i];
				}
				else if(numOperations3<minNumOperations[i]&&numOperations3!=-1)
				{
					minNumOperations[i]=numOperations3;
					Operations[i]=Operations_temp3[i];
				}
		}
	}
	return Operations[m];
}

int main() {
  unsigned long long n;
  std::cin >> n;
  vector<unsigned long long> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}