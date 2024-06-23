//����� 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
int stack[N], a[N];
int top, n;

int main() {
    cin >> n;

    // ��ȡÿ������ĵ���˳��
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    top = 0;
    bool possible = true; // ����Ƿ���ܵ��ȳɹ�

    // ģ�⳵�����
    for (int i = 1, cur = 1; i <= n && possible; ++i) {
        // ��cur����ʻ��ջ�У�ֱ��ջ�������С��cur
        while (cur <= a[i]) {
            stack[++top] = cur++;
        }

        // ���ջ������Ų�����a[i]��˵�����Ȳ�����
        if (stack[top] != a[i]) {
            possible = false;
            cout << "Impossible" << endl;
            break; // �˳�ѭ��
        }

        // ���ջ������ŵ���a[i]������ջ�������
        --top;
    }

    if (possible) {
        cout << "Possible" << endl;
    }

    return 0;
}
