//����������������Ϊ�麯����
#include <iostream>

class PolymorphicEmpty {
public:
    PolymorphicEmpty() {}
    virtual ~PolymorphicEmpty() {} // ����������
};

int main() {
    std::cout << "Size of class with virtual destructor: " << sizeof(PolymorphicEmpty) << std::endl;
    return 0;
}
/*
C++������һ������һ�����������麯���� �ͻ�Ϊ�����������麯���� ���ڸ����͵�ÿһ��ʵ�������һ��ָ��
�麯�����ָ�롣
32λ һ��ָ��4�ֽ�
64λ һ��ָ��8�ֽ� 
*/
