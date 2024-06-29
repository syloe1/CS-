#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main() {
	vector<int> data{};
	copy(istream_iterator<int>(cin),
		istream_iterator<int>(), 
		back_inserter(data));
	sort(data.begin(), data.end());
	copy(data.begin(), data.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}
