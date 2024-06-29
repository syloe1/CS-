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
// Ȼ���� main ������ʹ��
 // ��ȷ���� error(bool value)
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

    guess(byte); // ƥ�� guess(int)
    guess(shrt); // ƥ�� guess(int)
    guess(i);    // ƥ�� guess(int)
    guess(lng);  // ƥ�� guess(long)

    error(true); // ��ȷ���� error(bool value)
    // ����ĵ��ý�ƥ�� error(long value) ������ error(bool value)
    error(byte); // signed char ��ʽת��Ϊ long
    error(shrt); // short ��ʽת��Ϊ long
    error(i);    // int ��ʽת��Ϊ long
    error(lng);  // ƥ�� error(long value)

    return 0;
}
