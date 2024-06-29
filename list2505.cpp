#include <iostream>

// 定义字面量后缀 _S，将数字字面量转换为 short 类型
short operator "" _S(unsigned long long value) {
    return static_cast<short>(value);
}

// 重载 print 函数以打印 short 类型的值
void print(short s) {
    std::cout << "short=" << s << '\n';
}

// 重载 print 函数以打印 int 类型的值
void print(int i) {
    std::cout << "int=" << i << '\n';
}

int main() {
    print(42);        // 调用 print(int i)
    print(123_S);     // 正确使用字面量后缀 _S，调用 print(short s)
    return 0;
}
