#include <iostream>
using namespace std;

struct rational {
    int numerator; ///< ���ӣ����������ֵ�ķ���
    int denominator; ///< ��ĸ��ʼ��Ϊ����
};

int main() {
    rational pi {};
    pi.numerator = 355;
    pi.denominator = 113;

    // �ֱ�Ϊ���Ӻͷ�ĸ���ÿ��
    cout.width(4);
    cout << pi.numerator << "|"; // ʹ�� "|" ��Ϊ�ָ��������ڹ۲���Ч��
    cout.width(4);
    cout << pi.denominator << '\n'; // �����ĸ������

    return 0;
}
