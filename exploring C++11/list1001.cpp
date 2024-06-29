#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

int main() {
	vector<int> input { 10, 20, 30 };
	vector<int> output {};
	output.resize(input.size());
	copy(input.begin(), input.end(), output.begin());
	assert(input == output);
	return 0;
}
