#include <iostream>
#include <iterator>
#include <vector>
int main() {
	vector<int> data{};
	data.insert(data.begin(), 
			istream_iterator<int>(cin), istream_iterator<int>());
	vector<int>::iterator iter{} , end{data.end()};
	for (iter = data.begin(); iter != end and *iter == 0; ++iter) {
		//empty
	}
	if (iter == data.end()) cout<<"data contains all zeroes\n";
	else cout<<"data does not contain all zeroes\n";
	return 0;
}
