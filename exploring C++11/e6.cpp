#include <iostream>
using namespace std;

class A {
private:
    int value;
public:
    A(int n) { value = n; }           // 普通构造函数
    A(const A& other) { value = other.value; } // 复制构造函数
    void Print() { cout << value << endl; }    // 输出value
};

int main() {
    A a(10); // 创建A的实例a，并初始化为10
    A b = a; // 使用复制构造函数创建b，它是a的副本
    b.Print(); // 输出b的value，应该是10
    return 0;
}
