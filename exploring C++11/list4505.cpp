#include <iostream>
int main() {
	std::cin.exceptions(std::ios_base::badbit);
	std::cout.exceptions(std::ios_base::badbit);
	int x {};
	try {
		while (std::cin >> x)
			std::cout << x << '\n';
		if (not std::cin.eof()) // 你可以使用 std::cin.eof() 函数来检查输入流是否已经到达了文件结束标记。
			std::cerr << "Invalid integer input. Program terminated.\n";
	} catch(std::ios_base::failure const& ex) {
		std::cerr << "Major I/O failure! Program terminated.\n";
		std::terminate();
	}
}
