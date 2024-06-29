//��д�������������� ��һ��Sy��ʵ����ֵ������һ��ʵ���� ��һ��Sy��ʵ����ֵ�����Լ��� ������ֵ��

#include <iostream>
#include <cstring>

class Sy {
	public:
		// Ĭ�Ϲ���
		Sy(char *pData = nullptr) : m_pData(nullptr) {
			if (pData != nullptr) {
				m_pData = new char[strlen(pData) + 1];
				strcpy(m_pData, pData);
			}
		}
		// ���ƹ���
		Sy(const Sy& str) : m_pData(nullptr) {
			if (str.m_pData != nullptr) {
				m_pData = new char[strlen(str.m_pData) + 1];
				strcpy(m_pData, str.m_pData);
			}
		}
		// ��ֵ�����
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
		// ��������
		~Sy() {
			delete[] m_pData;
		}
		// ��ӡ��Ա����
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
	a.print(); // ��ӡa������
	b.print(); // ��ӡb������
}

void testSelfAssignment() {
	Sy a("Test self assignment");
	a = a; // �Ը�ֵ
	a.print(); // ��ӡa������
}

void testChainAssignment() {
	Sy a("First");
	Sy b("Second");
	Sy c;
	c = b = a; // ������ֵ
	a.print(); // ��ӡa������
	b.print(); // ��ӡb������
	c.print(); // ��ӡc������
}

int main() {
	testAssignment();
	testSelfAssignment();
	testChainAssignment();
	return 0;
}
