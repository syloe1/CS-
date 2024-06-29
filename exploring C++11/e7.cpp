//��ΪSy������Ӹ�ֵ�����������
#include <cstring>
class Sy {
public:
	//Ĭ�Ϲ��� 
	Sy(char *pData = nullptr) : m_pData(nullptr) {
		if (pData != nullptr) {
			m_pData = new char[strlen(pData) + 1];
			strcpy(m_pData, pData); //��һ���ַ������Ƶ���һ���ַ����� 
		}
	}
	//���ƹ��� 
	Sy(const Sy& str) :m_pData(nullptr) {
		if (str.m_pData != nullptr) {
			m_pData = new char [strlen(str.m_pData) + 1];
			strcpy(m_pData, str.m_pData);
		}
	} 
	//��ֵ�����
	Sy& operator = (const Sy& str)  {
		if (this == &str) return *this; //ͬһ��ʵ��ֱ�ӷ���
		delete[]  m_pData; //�ͷŵ�ǰ�������Դ
		//�������Դ 
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
