//����ڸ����������һ�����������͹��캯���� �ٶԸ�������sizeof���õ��Ľ�����Ƕ���
#include <iostream>

class NonEmpty {
public:
    NonEmpty() {}  // Ĭ�Ϲ��캯��
    ~NonEmpty() {} // ��������
};

int main() {
    std::cout << "Size of class with constructors and destructor: " << sizeof(NonEmpty) << std::endl;
    return 0;
}
//���ù��캯������������ֻ��Ҫ֪�������ĵ�ַ���ɣ� ������ַֻ��
//������ء� 
