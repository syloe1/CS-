#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
int main() {
	vector<int> data{};
	int x{};
	while (cin>>x) data.push_back(x);
	for (vector<int>::iterator st{data.begin()}, ed{data.end()}; 
		st != ed and st != --ed; ++st) 
		iter_swap(st, ed);
	copy(data.begin(), data.end(), ostream_iterator<int>(cout, "\n"));
	
	return 0;
}

