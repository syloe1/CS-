//ʹ�ú���ָ����ú���ʾ��
#include <iostream> 
using namespace std;

int test(int a); // ����ԭ������

int main() {
    // ֱ����� test �����ĵ�ַ
    cout << &test << endl;
    
    int (*fp)(int); // ����ָ��������ָ�����һ�� int ������ int �ĺ���
    fp = test; // ������ָ��ָ�� test ����
    
    // ʹ�ú���ָ����� test ����
    cout << fp(5) << ", " << (*fp)(10) << endl;
    return 0;
}

int test(int a) {
    return a; // test ����ʵ�֣��򵥵ط��ش���Ĳ���
}
