#include <iostream>
#include <string>
#include <utility>
#include <vector>
class mystring : public std::string {
	public:
		mystring() : std::string() {
			std::cout << "mystring()\n";
		}
		mystring(mystring const& copy) : std::string(copy) { //拷贝构造函数：
			std::cout << "mystring copy(\"" << *this << "\")\n";
		}
		mystring(mystring&& move) noexcept //noexcept 说明这个构造函数保证不会抛出异常。
	:
		std::string(std::move(move)) { //移动构造函数：
			std::cout << "mystring move(\"" << *this << "\")\n";
		}
};
std::vector<mystring> read_data() {
	std::vector<mystring> strings;
	mystring line;
	while (std::getline(std::cin, line))
		strings.push_back(std::move(line));
	return strings;
}
int main() {
	std::vector<mystring> strings;
	strings = read_data();
}
