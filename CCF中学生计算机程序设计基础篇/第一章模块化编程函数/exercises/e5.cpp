#include <iostream>
#include <string>
#include <cmath>

// 函数用于将单个数字转换为2的幂次方的和，并返回相应的字符串
std::string toPowerOfTwo(int num) {
    if (num == 0) return "2(0)";
    if (num == 1) return "2+2(0)";
    std::string result;
    while (num > 0) {
        int power = static_cast<int>(log2(num));
        result = "2(" + toPowerOfTwo(num - (1 << power)) + ")+" + result;
        num = num - (1 << power);
    }
    // 移除尾部的"+"符号
    if (!result.empty() && result.back() == '+') {
        result.pop_back();
    }
    return result;
}

// 主函数
int main() {
    int n;
    std::cin >> n;

    // 将整数n转换为2的幂次方的和的字符串表示
    std::string representation = toPowerOfTwo(n);

    // 输出结果
    std::cout << representation << std::endl;

    return 0;
}
