#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main()
{
	vector<int> data{};
	/*
	使用 std::copy 函数从标准输入（cin）复制整数到 data 容器中。istream_iterator<int>(cin) 是一个输入迭代器，它读取 cin 中的整数。istream_iterator<int>() 是一个结束迭代器，表示输入结束。back_inserter(data) 是一个插入迭代器，它将元素插入到 data 的末尾。
	*/
	copy(istream_iterator<int>(cin), 
		istream_iterator<int>(),
		back_inserter(data));
	//data.begin() 作为第三个参数，表示结果将被写入到 data 容器的开始位置。这意味着原地修改 data 中的元素。

	//[](int x) { return x * 2; } 是一个 lambda 表达式，它定义了一个匿名函数，该函数接受一个整数 x 作为参数，并返回 x 乘以 2 的结果。
	transform(data.begin(), data.end(), data.begin(), [](int x) {
		return x * 2;
	});
	copy(data.begin(), data.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}
