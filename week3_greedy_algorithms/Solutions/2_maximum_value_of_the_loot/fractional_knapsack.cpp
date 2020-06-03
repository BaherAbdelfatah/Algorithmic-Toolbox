#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
#include<stdio.h>
#include<cmath>
#include <set> 
#include <iterator>
#include <ctype.h>
#include <sstream>
using namespace std;
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
void swap(double *xp, double *yp)  
{  
    double temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
} 
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  unsigned int n = weights.size();
  vector<double> values_weights(n);
  for(unsigned int i=0;i<n;i++)
  {
	  values_weights[i]=double(values[i])/weights[i];
  }
  for (unsigned int i = 0; i < n-1; i++)      
  {    
    for (unsigned int j = 0; j < n-i-1; j++)  
    {
		  if (values_weights[j] < values_weights[j+1])
		  {
            swap(&values_weights[j], &values_weights[j+1]);
			swap(&weights[j], &weights[j+1]);
		  }
	}
  }
  unsigned int index=0;
  while(capacity>0)
  {
	  value+=values_weights[index]*min(weights[index],capacity);
	  capacity-=min(weights[index],capacity);
	  weights[index]-=min(weights[index],capacity);
	  if(index<n-1)
		index++;
	  if(weights[index]==0)
		  break;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
