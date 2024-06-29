//编写三个测试用例。 把一个Sy的实例赋值给另外一个实例。 把一个Sy的实例赋值给它自己。 连续赋值。

#include <iostream>
#include <cstring>

class Sy {
	public:
		// 默认构造
		Sy(char *pData = nullptr) : m_pData(nullptr) {
			if (pData != nullptr) {
				m_pData = new char[strlen(pData) + 1];
				strcpy(m_pData, pData);
			}
		}
		// 复制构造
		Sy(const Sy& str) : m_pData(nullptr) {
			if (str.m_pData != nullptr) {
				m_pData = new char[strlen(str.m_pData) + 1];
				strcpy(m_pData, str.m_pData);
			}
		}
		// 赋值运算符
		Sy& operator=(const Sy& str) {
			if (this == &str) return *this;
			delete[] m_pData;
			if (str.m_pData != nullptr) {
				m_pData = new char[strlen(str.m_pData) + 1];
				strcpy(m_pData, str.m_pData);
			} else {
				m_pData = nullptr;
			}
			return *this;
		}
		// 析构函数
		~Sy() {
			delete[] m_pData;
		}
		// 打印成员函数
		void print() const {
			std::cout << (m_pData ? m_pData : "nullptr") << std::endl;
		}

	private:
		char* m_pData;
};

void testAssignment() {
	Sy a("Hello, World!");
	Sy b;
	b = a;
	a.print(); // 打印a的内容
	b.print(); // 打印b的内容
}

void testSelfAssignment() {
	Sy a("Test self assignment");
	a = a; // 自赋值
	a.print(); // 打印a的内容
}

void testChainAssignment() {
	Sy a("First");
	Sy b("Second");
	Sy c;
	c = b = a; // 连续赋值
	a.print(); // 打印a的内容
	b.print(); // 打印b的内容
	c.print(); // 打印c的内容
}

int main() {
	testAssignment();
	testSelfAssignment();
	testChainAssignment();
	return 0;
}
