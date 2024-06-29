#include <iostream>
#include <vector>
int main() {
	std::vector<int> data { 10, 20 };
	data[5] = 0;
	std::cout << data[5] << '\n';
}
