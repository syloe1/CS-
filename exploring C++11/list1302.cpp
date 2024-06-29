#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


using namespace std;
int main() {
	vector<int> data {};
	data.insert(data.begin(), istream_iterator<int>(cin), istream_iterator<int>());
	for (vector<int>::iterator iter {data.begin()}, end {data.end()}; iter != end; ) {
		int value {*iter};
		vector<int>::iterator here {lower_bound(data.begin(), iter, value)};
		if (iter == here) ++iter;
		else {
			iter = data.erase(iter);
			data.insert(here, value);
		}
	}
	for (vector<int>::iterator iter {data.begin()}, prev {data.end()}, end {data.end()};
	        iter != end;  ++iter) {
		if (prev != data.end())	     {
			assert(*iter < *prev);
		}
		prev = iter;
	}
	cout<<'{';
	string separator{" "};
	for (int ele : data) {
		cout<<separator<<ele;
		separator = ", ";
	}
	cout<<" }\n";
	return 0;
}

