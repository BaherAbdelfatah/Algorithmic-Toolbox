#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int countInRange(vector<int> &a,int n,int left, int right) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        if (a[i] == n) {
            count++;
        }
    }
    return count;
}
int get_majority_element(vector<int> &a, int left, int right) {
	if (left == right) return a[left];
	//write your code here
	int mid = left + (right-left)/2;
	int x = get_majority_element(a,left,mid);
	int y = get_majority_element(a,mid+1,right);
	if(x==y)
		return x;
	int leftCount = countInRange(a, x, left, right);
	int rightCount = countInRange(a, y, left, right);
	int n=(right-left)+1;
	if(leftCount > rightCount && leftCount > n/2)
		return x;
	else if(rightCount > leftCount && rightCount > n/2)
		return y;
	else 
		return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}