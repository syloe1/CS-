#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    vector<int> data{};
    int x{};
    while (cin >> x) 
        data.push_back(x);
    
    // 使用基于范围的 for 循环，这是 C++11 推荐的迭代器使用方式
    for (auto i = data.begin(); i != data.end(); ++i) {
        cout << setw(2) << *i      // 打印数字，宽度为2
             << setw(3) << (*i) * 2  // 打印数字的两倍，宽度为3
             << setw(4) << (*i) * (*i) << '\n';  // 打印数字的平方，宽度为4，然后换行
    }
    return 0;
}
