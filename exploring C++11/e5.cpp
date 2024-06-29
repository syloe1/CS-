//如果把析构函数标记为虚函数呢
#include <iostream>

class PolymorphicEmpty {
public:
    PolymorphicEmpty() {}
    virtual ~PolymorphicEmpty() {} // 虚析构函数
};

int main() {
    std::cout << "Size of class with virtual destructor: " << sizeof(PolymorphicEmpty) << std::endl;
    return 0;
}
/*
C++编译器一旦发现一个类型中有虚函数， 就会为该类型生成虚函数表， 并在该类型的每一个实例中添加一个指向
虚函数表的指针。
32位 一个指针4字节
64位 一个指针8字节 
*/
