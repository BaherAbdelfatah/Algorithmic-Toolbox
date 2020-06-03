#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  if(n<3)
	  return vector<int> (1,n);
  int counter=1;
  while(n>0)
  {
	  summands.push_back(counter);
	  n-=counter;
	  if(n>=2*(counter+1)+1)
	  {
		counter++;
	  }
	  else
	  {
		summands.push_back(n);
		n=0;
	  }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
