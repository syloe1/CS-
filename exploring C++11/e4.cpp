//如果在该类型中添加一个析构函数和构造函数， 再对该类型求sizeof，得到的结果又是多少
#include <iostream>

class NonEmpty {
public:
    NonEmpty() {}  // 默认构造函数
    ~NonEmpty() {} // 析构函数
};

int main() {
    std::cout << "Size of class with constructors and destructor: " << sizeof(NonEmpty) << std::endl;
    return 0;
}
//调用构造函数和析构函数只需要知道函数的地址即可， 函数地址只与
//类型相关。 
