#include <iostream>

// 全局命名空间中的print函数，专门打印int类型的值
void print(int i) {
	std::cout << "int: " << i << '\n';
}

// labeled命名空间，包含一个print函数，专门打印double类型的值
namespace labeled {
	void print(double d) {
		std::cout << "double: " << d << '\n';
	}
}

// simple命名空间，包含两个print函数，分别打印int和double类型的值
// 但它们没有指定返回类型，这是不正确的，需要添加返回类型std::ostream
namespace simple {
	std::ostream& print(std::ostream& os, int i) {
		os << i << '\n';
		return os;
	}
	std::ostream& print(std::ostream& os, double d) {
		os << d << '\n';
		return os;
	}
}

// test_simple函数测试simple命名空间中的print函数
void test_simple() {
	using namespace simple;
	// 调用simple命名空间中的print(int)，但由于函数没有重载解析为int，这里将报错
	print(42);
	// 调用simple命名空间中的print(double)
	print(3.14159);
}

// test_labeled函数测试labeled命名空间中的print函数
void test_labeled() {
	using namespace labeled;
	// 由于labeled命名空间中只有print(double)，这里将调用全局命名空间的print(int)
	print(42);
	// 调用labeled命名空间中的print(double)
	print(3.14159);
}

int main() {
	test_simple();
	test_labeled();
}
