#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
int main() {
	std::vector<int> data {};
	std::cout << "Multiplier: ";
	int multiplier {};
	std::cin >> multiplier;
	std::cout << "Data:\n";
	std::copy(std::istream_iterator<int>(std::cin),
	          std::istream_iterator<int>(),
	          std::back_inserter(data));
	std::transform(data.begin(), data.end(), data.begin(),
	[multiplier](int i) {  //[multiplier]：这是一个捕获子句，它表示lambda表达式会捕获外部的 multiplier 变量。这里的捕获方式是值捕获（即复制 multiplier 的值到lambda表达式内部），因此lambda内部使用的 multiplier 是调用 std::transform 时传入的值。
		return i * multiplier;
	});
	std::copy(data.begin(), data.end(),
	          std::ostream_iterator<int>(std::cout, "\n"));
}
