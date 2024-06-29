#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

// ��ӡ����������ָ�����
void print(int i, int width) {
    cout.width(width);  //��������� cout ���ֶο��
    cout << i;
    cout.width(0); // ���ÿ�ȣ�����Ӱ��������
}

// ��ӡ���������������е���ʽ
void print(const vector<int>& vec, int width, const string& prefix, const string& separator, const string& postfix) {
    cout << prefix;
    bool print_separator = false;
    for (auto x : vec) {
        if (print_separator) {
            cout << separator;   
        } else {
            print_separator = true;
        }
        print(x, width); // ʹ�ÿ�ȴ�ӡ����
    }
    cout << postfix;
}

// ��ӡ������������ָ����ȣ��������д�ӡ
void print(const vector<int>& vec, const string& prefix, const string& separator, const string& postfix) {
    print(vec, 0, prefix, separator, postfix);
}

int main() {
    vector<int> data {10, 20, 30, 40, 100, 1000};

    cout << "columnar data:\n";
    print(data, 10, "", "\n", "\n"); // �д�ӡ�����Ϊ10����ǰ׺�ͺ�׺

    cout << "row data:\n";
    print(data, "{", ", ", "}\n"); // �д�ӡ��ʹ�ô����źͶ�����Ϊ�ָ�

    return 0;
}
