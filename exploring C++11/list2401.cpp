#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

// 打印整数，按照指定宽度
void print(int i, int width) {
    cout.width(width);  //设置输出流 cout 的字段宽度
    cout << i;
    cout.width(0); // 重置宽度，以免影响后续输出
}

// 打印整数向量，按照列的形式
void print(const vector<int>& vec, int width, const string& prefix, const string& separator, const string& postfix) {
    cout << prefix;
    bool print_separator = false;
    for (auto x : vec) {
        if (print_separator) {
            cout << separator;   
        } else {
            print_separator = true;
        }
        print(x, width); // 使用宽度打印整数
    }
    cout << postfix;
}

// 打印整数向量，不指定宽度，即不按列打印
void print(const vector<int>& vec, const string& prefix, const string& separator, const string& postfix) {
    print(vec, 0, prefix, separator, postfix);
}

int main() {
    vector<int> data {10, 20, 30, 40, 100, 1000};

    cout << "columnar data:\n";
    print(data, 10, "", "\n", "\n"); // 列打印，宽度为10，无前缀和后缀

    cout << "row data:\n";
    print(data, "{", ", ", "}\n"); // 行打印，使用大括号和逗号作为分隔

    return 0;
}
