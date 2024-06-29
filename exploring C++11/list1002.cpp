#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> data{};
    int x{};
    while (cin >> x) 
        data.push_back(x);
    sort(data.begin(), data.end());
    // 使用基于范围的 for 循环，这是 C++11 推荐的迭代器使用方式
    for (auto i = data.begin(); i != data.end(); ++i) 
        cout << *i << '\n';
    return 0;
}
