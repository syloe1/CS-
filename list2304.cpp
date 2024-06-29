/*
#include <iostream>
int main() {
    int x {0}; // 外部x的定义
    auto lambda = [&x](int y) { // 通过引用捕获x
        x = 1; // 修改外部x的值
        y = 2; // 这里修改y实际上不会影响传递给lambda的实参
        return x + y; // 返回x和y的和
    };
    int local {0};
    std::cout << lambda(local) << ", " << x << ", " << local << '\n'; // 输出lambda的返回值，外部x的值，以及local的值
}
*/
#include <iostream>
int main() {
	int x {0};
	auto lambda = [x](int y) mutable {
		x = 1;
		y = 2;
		return x + y;
	};
	int local {0};
	std::cout << lambda(local) << ", " << x << ", " << local << '\n';
}

