#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
	stops.push_back(dist);
	if(dist<=tank)
		return 0;
	unsigned int numRefills=0,currentRefill=0;
	unsigned int n=stops.size()-2;
	while(currentRefill<=n)
	{
		unsigned int lastRefill=currentRefill;
		while(currentRefill<=n &&(stops[currentRefill+1]-stops[lastRefill]<=tank))
		{
			currentRefill++;
		}
		if(currentRefill==lastRefill)
			return -1;
		if(currentRefill<=n)
			numRefills++;
	}
    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
	stops.push_back(0);
    for (size_t i = 1; i <= n; ++i)

		cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
