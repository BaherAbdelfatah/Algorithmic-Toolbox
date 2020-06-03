#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;
using std::string;

void swap(string *xp, string *yp)  
{  
    string temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

bool myCompare(string a, string b)  
{  	
	string ab=a+b;
	string ba=b+a;
	return ab.compare(ba) > 0 ? 1: 0; 
}

string largest_number(vector<string> a) {
  //write your code here

  sort(a.begin(), a.end(), myCompare);

  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}