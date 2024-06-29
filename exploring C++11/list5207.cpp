#include <iostream>

// 定义一个全局函数print，用于打印int类型的值
void print(int i) {
    std::cout << "int: " << i << '\n';
}

// 定义一个命名空间labeled，并在其内部定义一个print函数，用于打印double类型的值
namespace labeled {
    void print(double d) {
        std::cout << "double: " << d << '\n';
    }
}

// 定义一个命名空间simple，并在其内部定义两个print函数，分别用于打印int和double类型的值
namespace simple {
    void print(int i) {
        std::cout << i << '\n'; // 注意：这里没有前缀"int: "，与全局print(int)不同
    }
    void print(double d) {
        std::cout << d << '\n';
    }
}

// test_simple函数用于测试simple命名空间中的print函数
// 使用using声明来引入simple命名空间中的print函数
void test_simple() {
    using simple::print;
    print(42);        // 调用simple::print(int)
    print(3.14159);   // 调用simple::print(double)
}

// test_labeled函数用于测试labeled命名空间中的print函数
// 使用using声明来引入labeled命名空间中的print函数
void test_labeled() {
    using labeled::print;
    // 由于全局也有print(int)函数，这里将调用全局的print(int)
    print(42);
    // 调用labeled::print(double)
    print(3.14159);
}

// 主函数
int main() {
    test_simple();    // 测试simple命名空间的print函数
    test_labeled();  // 测试labeled命名空间的print函数
}
