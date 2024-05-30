// file: 1config10.cpp 
// 测试 template参数可否根据前㆒个 template参数而设定默认值。
// test __STL_LIMITED_DEFAULT_TEMPLATES in <stl_config.h> 
// ref. C++ Primer 3/e, p.816 
// vc6[o] cb4[o] gcc[o]

// 如果编译器支持一个template参数可以根据前一个template的参数设置就定义。

#include <iostream>
#include <cstddef> // for size_t
using namespace std;

class alloc {
};

template <class T, class Alloc=alloc, size_t BufSiz=0>
class deque {
public:
    deque() {
        cout << "deque()" << endl;
    }
};

template <class T, class Sequence = deque<T>> //Sequence 是一个模板参数，表示用于实现 stack 的底层容器，默认值是 deque<T>。
class stack {
public:
    stack() {
        cout << "stack" << endl;
    }
private:
    Sequence c;
};

int main() {
    stack<int> x;
}