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
    // ʹ�û��ڷ�Χ�� for ѭ�������� C++11 �Ƽ��ĵ�����ʹ�÷�ʽ
    for (auto i = data.begin(); i != data.end(); ++i) 
        cout << *i << '\n';
    return 0;
}
