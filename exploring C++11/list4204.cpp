#include <algorithm>
#include <vector>
int main() {
	std::vector<int> vec(10);
	int state;
	std::generate(vec.begin(), vec.end(), [&state]() {
		return ++state;
	});
}
