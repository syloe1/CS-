#include <iostream>
using namespace std;

int main() {
    cout << "This program prints a table of squares.\n";
    cout << "Enter the starting value for the table: ";
    int start = 0;
    cin >> start;
    cout << "Enter the ending value for the table: ";
    int end = start; // Ӧ��ʹ�ø�ֵ�����
    cin >> end; // �����������
    cout << endl << "#   #^2\n";
    for (int x = start; x <= end; ++x) { // ʹ��forѭ������while������������
        cout << x << "   " << x * x << "\n";
    }
    return 0;
}
