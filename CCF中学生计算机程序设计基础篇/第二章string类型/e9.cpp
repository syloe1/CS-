//�����滻
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string s, s1, s2;
    getline(cin, s); // ��ȡԭʼ�ı�
    getline(cin, s1); // ��ȡҪ���滻�ĵ���
    getline(cin, s2); // ��ȡ�滻��ĵ���

    // ȷ���滻������ԭʼ�ı��н���
    for (int k = 0; (k = s.find(s1, k)) != string::npos; k += s1.size()) {
        s.replace(k, s1.size(), s2);
    }

    // ����滻��Ľ��
    cout << s;

    return 0;
}
