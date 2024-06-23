//使用函数指针调用函数示例
#include <iostream> 
using namespace std;

int test(int a); // 函数原型声明

int main() {
    // 直接输出 test 函数的地址
    cout << &test << endl;
    
    int (*fp)(int); // 函数指针声明，指向接受一个 int 并返回 int 的函数
    fp = test; // 将函数指针指向 test 函数
    
    // 使用函数指针调用 test 函数
    cout << fp(5) << ", " << (*fp)(10) << endl;
    return 0;
}

int test(int a) {
    return a; // test 函数实现，简单地返回传入的参数
}
