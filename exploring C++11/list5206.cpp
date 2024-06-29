#include <iostream>

// ȫ�������ռ��е�print������ר�Ŵ�ӡint���͵�ֵ
void print(int i) {
	std::cout << "int: " << i << '\n';
}

// labeled�����ռ䣬����һ��print������ר�Ŵ�ӡdouble���͵�ֵ
namespace labeled {
	void print(double d) {
		std::cout << "double: " << d << '\n';
	}
}

// simple�����ռ䣬��������print�������ֱ��ӡint��double���͵�ֵ
// ������û��ָ���������ͣ����ǲ���ȷ�ģ���Ҫ��ӷ�������std::ostream
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

// test_simple��������simple�����ռ��е�print����
void test_simple() {
	using namespace simple;
	// ����simple�����ռ��е�print(int)�������ں���û�����ؽ���Ϊint�����ｫ����
	print(42);
	// ����simple�����ռ��е�print(double)
	print(3.14159);
}

// test_labeled��������labeled�����ռ��е�print����
void test_labeled() {
	using namespace labeled;
	// ����labeled�����ռ���ֻ��print(double)�����ｫ����ȫ�������ռ��print(int)
	print(42);
	// ����labeled�����ռ��е�print(double)
	print(3.14159);
}

int main() {
	test_simple();
	test_labeled();
}
