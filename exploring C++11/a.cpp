#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double const pi = 3.141592653589792;
    cout.precision(12); // ���þ���Ϊ12λС��
    cout << pi << '\n';   // ��ӡ pi ��ֵ

    cout << setprecision(4); // �������þ���Ϊ4λС���������ں������
    cout << pi << '\n';        // �ٴδ�ӡ pi ��ֵ�����ʹ��4λС������

    return 0;
}
