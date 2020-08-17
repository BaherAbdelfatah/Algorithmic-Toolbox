#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;

struct Interval { 
    int x, y; 
}; 
  
// Compares two intervals according to staring times. 
bool compareInterval_x(Interval i1, Interval i2) 
{ 
    return (i1.x < i2.x); 
} 

bool compareInterval_y(Interval i1, Interval i2) 
{ 
    return (i1.y < i2.y); 
} 

double computeDistance(Interval point_0, Interval point_1) 
{ 
    return double(sqrt(pow(point_0.x-point_1.x,2)+pow(point_0.y-point_1.y,2))); 
} 

double minimal_distance(vector<Interval> points,int low,int high) {
  //write your code here
	int size = high - low;
	if(size==1)
	{
		return double(computeDistance(points[high],points[low]));
	}
	int mid=(high - low)/2+low;
	double part_one = minimal_distance(points,low,mid);
	double part_two = minimal_distance(points,mid,high);
	double x_mid_line = points[mid].x;
	double min_distance=min(part_one,part_two);
	bool enter = false;
	vector<Interval> mid_points;
	for(int i=1;i<(high - low)/2;i++)
	{
		enter = false;
		if(fabs(points[mid-i].x-x_mid_line)<min_distance)
		{
				mid_points.push_back(points[mid-i]);
				enter=true;
		}
		if(fabs(points[mid+i].x-x_mid_line)<min_distance)
		{

				mid_points.push_back(points[mid+i]);
				enter=true;
		}
		if(enter == false)
			break;
	}

	sort(mid_points.begin(), mid_points.end(), compareInterval_y); 
	
	double min_mid_distance=min_distance;
	if(mid_points.size()>0)
	for(int i=0;i<mid_points.size();i++)
	{	
		for(int j=i+1;j<mid_points.size()&& ((mid_points[j].y - mid_points[i].y) < min_mid_distance);j++)
		{
			double temp_dist=computeDistance(mid_points[i],mid_points[j]);
			if(temp_dist<min_mid_distance)
				min_mid_distance=temp_dist;
		}
	}
	min_distance=min(min_distance,min_mid_distance);
    return min_distance;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<Interval> points(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
	  std::cin >> points[i].x >> points[i].y ;
  }
  sort(points.begin(), points.end(), compareInterval_x); 
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points,0,points.size()-1) << "\n";
}
