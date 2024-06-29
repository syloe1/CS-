#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
int main() {
	std::vector<int> data { 1, 2, 3 };
	int multiplier {3};
	auto times = &[multiplier](int i) {
		return i * multiplier;
	};
	auto times = [multiplier](int i) {
		return i * multiplier;
	};
	std::transform(data.begin(), data.end(), data.begin(), times); //这是一个函数或函数对象，用于定义如何转换输入范围中的每个元素。
	multiplier = 20;
	std::transform(data.begin(), data.end(), data.begin(), times);
	std::copy(data.begin(), data.end(),
	          std::ostream_iterator<int>(std::cout, "\n"));
}

