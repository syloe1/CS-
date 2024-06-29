//请为Sy类型添加赋值运算符函数。
#include <cstring>
class Sy {
public:
	//默认构造 
	Sy(char *pData = nullptr) : m_pData(nullptr) {
		if (pData != nullptr) {
			m_pData = new char[strlen(pData) + 1];
			strcpy(m_pData, pData); //将一个字符串复制到另一个字符串中 
		}
	}
	//复制构造 
	Sy(const Sy& str) :m_pData(nullptr) {
		if (str.m_pData != nullptr) {
			m_pData = new char [strlen(str.m_pData) + 1];
			strcpy(m_pData, str.m_pData);
		}
	} 
	//赋值运算符
	Sy& operator = (const Sy& str)  {
		if (this == &str) return *this; //同一个实例直接返回
		delete[]  m_pData; //释放当前对象的资源
		//深拷贝新资源 
		if (str.m_pData != nullptr)  {
			m_pData = new char [strlen(str.m_pData) + 1];
			strcpy(m_pData, str.m_pData);
		} else {
			m_pData = nullptr;
		}
		return *this;
	}
	~Sy(void) {
		delete[] m_pData;
	}
private:
	char* m_pData; 
}; 
