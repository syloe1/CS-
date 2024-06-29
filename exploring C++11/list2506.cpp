#include <iostream>
// print is overloaded for signed char, short, int and long
void print(signed char value) {
	std::cout << "print(signed char = " << static_cast<int>(value) << ")\n";
}
void print(short value) {
	std::cout << "print(short = " << value << ")\n";
}
void print(int value) {
	std::cout << "print(int = " << value << ")\n";
}
void print(long value) {
	std::cout << "print(long = " << value << ")\n";
}
// guess is overloaded for bool, int, and long
void guess(bool value) {
	std::cout << "guess(bool = " << value << ")\n";
}
void guess(int value) {
	std::cout << "guess(int = " << value << ")\n";
}
void guess(long value) {
	std::cout << "guess(long = " << value << ")\n";
}
void error(bool value) {
    std::cout << "error(bool = " << value << ")\n";
}
// 然后在 main 函数中使用
 // 正确调用 error(bool value)
void error(long value) {
	std::cout << "error(long = " << value << ")\n";
}
int main() {
    signed char byte {10};
    short shrt {20};
    int i {30};
    long lng {40};

    print(byte);
    print(shrt);
    print(i);
    print(lng);

    guess(byte); // 匹配 guess(int)
    guess(shrt); // 匹配 guess(int)
    guess(i);    // 匹配 guess(int)
    guess(lng);  // 匹配 guess(long)

    error(true); // 正确调用 error(bool value)
    // 下面的调用将匹配 error(long value) 而不是 error(bool value)
    error(byte); // signed char 隐式转换为 long
    error(shrt); // short 隐式转换为 long
    error(i);    // int 隐式转换为 long
    error(lng);  // 匹配 error(long value)

    return 0;
}
