#include <iostream>
using namespace std;

struct rational {
    int numerator; ///< 分子，获得有理数值的符号
    int denominator; ///< 分母，始终为正数
};

int main() {
    rational pi {};
    pi.numerator = 355;
    pi.denominator = 113;

    // 分别为分子和分母设置宽度
    cout.width(4);
    cout << pi.numerator << "|"; // 使用 "|" 作为分隔符，便于观察宽度效果
    cout.width(4);
    cout << pi.denominator << '\n'; // 输出分母并换行

    return 0;
}
