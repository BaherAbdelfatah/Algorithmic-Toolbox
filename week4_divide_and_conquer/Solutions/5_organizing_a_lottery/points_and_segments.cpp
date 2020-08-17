#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std; 

struct Interval { 
    int start, end; 
}; 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
} 

vector<int> fast_count_segments(vector<Interval> start_end, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
   for (size_t i = 0; i < points.size(); i++) {
	if(points[i]>=start_end[0].start)
    for (size_t j = 0; j < start_end.size(); j++) {
		if(points[i]<start_end[j].start)
			break;
		cnt[i] += start_end[j].start <= points[i] && points[i] <= start_end[j].end;
    }
  }
  return cnt;
}

vector<int> naive_count_segments(vector<Interval> start_end, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < start_end.size(); j++) {
		cnt[i] += start_end[j].start <= points[i] && points[i] <= start_end[j].end;
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<Interval> start_end(n);
  for (size_t i = 0; i < start_end.size(); i++) {
	  std::cin >> start_end[i].start >> start_end[i].end;
  }
  sort(start_end.begin(), start_end.end(), compareInterval); 
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(start_end, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
