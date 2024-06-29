#include <iostream>
#include <iomanip> // 用于使用制表符等功能

int main() {
    // 使用 C++11 的列表初始化语法初始化一个字符串字面量
    std::string header = " N   N^2    N^3\n";
    std::cout << header;
    
    // 基于范围的 for 循环，C++11 引入的特性
    for (auto i = 1; i != 21; ++i) {
        // 使用 C++11 的 auto 关键字进行类型推导
        auto square = i * i;
        auto cube = i * i * i;
        
        // 使用 << 操作符进行输出
        std::cout << std::setw(4) << i << '\t' 
                  << std::setw(4) << square << '\t' 
                  << std::setw(4) << cube << '\n';
    }
    return 0;
}
