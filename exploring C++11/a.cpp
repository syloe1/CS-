#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double const pi = 3.141592653589792;
    cout.precision(12); // 设置精度为12位小数
    cout << pi << '\n';   // 打印 pi 的值

    cout << setprecision(4); // 重新设置精度为4位小数，作用于后续输出
    cout << pi << '\n';        // 再次打印 pi 的值，这次使用4位小数精度

    return 0;
}
