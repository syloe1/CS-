#include <iostream>
using namespace std;

class A {
private:
    int value;
public:
    A(int n) { value = n; }           // ��ͨ���캯��
    A(const A& other) { value = other.value; } // ���ƹ��캯��
    void Print() { cout << value << endl; }    // ���value
};

int main() {
    A a(10); // ����A��ʵ��a������ʼ��Ϊ10
    A b = a; // ʹ�ø��ƹ��캯������b������a�ĸ���
    b.Print(); // ���b��value��Ӧ����10
    return 0;
}
