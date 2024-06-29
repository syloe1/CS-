#include <iostream>

// ����һ��ȫ�ֺ���print�����ڴ�ӡint���͵�ֵ
void print(int i) {
    std::cout << "int: " << i << '\n';
}

// ����һ�������ռ�labeled���������ڲ�����һ��print���������ڴ�ӡdouble���͵�ֵ
namespace labeled {
    void print(double d) {
        std::cout << "double: " << d << '\n';
    }
}

// ����һ�������ռ�simple���������ڲ���������print�������ֱ����ڴ�ӡint��double���͵�ֵ
namespace simple {
    void print(int i) {
        std::cout << i << '\n'; // ע�⣺����û��ǰ׺"int: "����ȫ��print(int)��ͬ
    }
    void print(double d) {
        std::cout << d << '\n';
    }
}

// test_simple�������ڲ���simple�����ռ��е�print����
// ʹ��using����������simple�����ռ��е�print����
void test_simple() {
    using simple::print;
    print(42);        // ����simple::print(int)
    print(3.14159);   // ����simple::print(double)
}

// test_labeled�������ڲ���labeled�����ռ��е�print����
// ʹ��using����������labeled�����ռ��е�print����
void test_labeled() {
    using labeled::print;
    // ����ȫ��Ҳ��print(int)���������ｫ����ȫ�ֵ�print(int)
    print(42);
    // ����labeled::print(double)
    print(3.14159);
}

// ������
int main() {
    test_simple();    // ����simple�����ռ��print����
    test_labeled();  // ����labeled�����ռ��print����
}
