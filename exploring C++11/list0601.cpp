#include <iostream>
using namespace std;

int main() {
    cout << "This program prints a table of squares.\n";
    cout << "Enter the starting value for the table: ";
    int start = 0;
    cin >> start;
    cout << "Enter the ending value for the table: ";
    int end = start; // 应该使用赋值运算符
    cin >> end; // 修正输入语句
    cout << endl << "#   #^2\n";
    for (int x = start; x <= end; ++x) { // 使用for循环代替while，并修正条件
        cout << x << "   " << x * x << "\n";
    }
    return 0;
}
