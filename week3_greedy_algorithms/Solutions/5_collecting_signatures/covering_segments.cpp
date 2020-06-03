#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
using std::vector;

struct Segment {
  int start, end;
};
bool compareInterval(Segment i1, Segment i2) 
{ 
    return (i1.start < i2.start); 
} 
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end(), compareInterval);
  /*for (size_t i = 0; i < segments.size()-1; ++i) 
  {
	  if(segments[i].end>=segments[i+1].start)
	  {
		  Segment temp;
		  temp.start=segments[i].start;
		  temp.end=max(segments[i].end,segments[i+1].end);	  
		  segments[i]=temp;
		  segments.erase(segments.begin()+i+1);
	  }
  }
  */
  for (size_t i = 0; i < segments.size()-1; ++i) 
  {
	  for (size_t j = i+1; j < segments.size(); ++j) 
	  {
		  if(segments[i].start<=segments[j].start&&segments[i].end>=segments[j].end)
		  {
			  segments.erase(segments.begin()+i);
		  }
	  }
  }

  for (size_t i = 0; i < segments.size()-1; ++i) 
  {
	  bool enter = false;
	  for (size_t j = i+1; j < segments.size(); ++j) 
	  {
		  if(segments[i].end>=segments[j].start)
		  {
			  segments[i].start=segments[j].start;
			  segments[i].end = min(segments[i].end,segments[j].end);
			  segments.erase(segments.begin()+j);
			  j--;
			  enter = true;
		  }
	  }
	  if(enter==true)
		  i--;
  }
  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
	//cout<<segments[i].start<<" "<<segments[i].end<<endl;
    points.push_back(segments[i].start);
    //points.push_back(segments[i].end);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
