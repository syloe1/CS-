#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    vector<int> data{};
    int x{};
    while (cin >> x) 
        data.push_back(x);
    
    // ʹ�û��ڷ�Χ�� for ѭ�������� C++11 �Ƽ��ĵ�����ʹ�÷�ʽ
    for (auto i = data.begin(); i != data.end(); ++i) {
        cout << setw(2) << *i      // ��ӡ���֣����Ϊ2
             << setw(3) << (*i) * 2  // ��ӡ���ֵ����������Ϊ3
             << setw(4) << (*i) * (*i) << '\n';  // ��ӡ���ֵ�ƽ�������Ϊ4��Ȼ����
    }
    return 0;
}
