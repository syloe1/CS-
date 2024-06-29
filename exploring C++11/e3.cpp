//定义一个空的类型， 里面没有任何成员变量和成员函数。 对该类型求sizeof， 得到的结果是多少
#include <iostream>

class Empty {
};

int main() {
    std::cout << "Size of empty class: " << sizeof(Empty) << std::endl;
    return 0;
}
//。这是因为即使空类不包含任何成员，编译器也会为其分配至少一个字节的空间，以确保不同空类对象的地址是唯一的。
