#include <iostream>

// ������������׺ _S��������������ת��Ϊ short ����
short operator "" _S(unsigned long long value) {
    return static_cast<short>(value);
}

// ���� print �����Դ�ӡ short ���͵�ֵ
void print(short s) {
    std::cout << "short=" << s << '\n';
}

// ���� print �����Դ�ӡ int ���͵�ֵ
void print(int i) {
    std::cout << "int=" << i << '\n';
}

int main() {
    print(42);        // ���� print(int i)
    print(123_S);     // ��ȷʹ����������׺ _S������ print(short s)
    return 0;
}
