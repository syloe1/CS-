#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main() {
	vector<int> data{};
	data.insert(data.end(),
		istream_iterator<int>(cin), istream_iterator<int>());
	reverse(data.begin(), data.end());
	copy(data.begin(), data.end(), ostream_iterator<int>(cout, "\n"));
	
	return 0;
}

