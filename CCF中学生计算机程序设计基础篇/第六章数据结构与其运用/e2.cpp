//火车入轨 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
int stack[N], a[N];
int top, n;

int main() {
    cin >> n;

    // 读取每个车厢的调度顺序
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    top = 0;
    bool possible = true; // 标记是否可能调度成功

    // 模拟车厢调度
    for (int i = 1, cur = 1; i <= n && possible; ++i) {
        // 将cur车厢驶入栈中，直到栈顶车厢号小于cur
        while (cur <= a[i]) {
            stack[++top] = cur++;
        }

        // 如果栈顶车厢号不等于a[i]，说明调度不可能
        if (stack[top] != a[i]) {
            possible = false;
            cout << "Impossible" << endl;
            break; // 退出循环
        }

        // 如果栈顶车厢号等于a[i]，弹出栈顶车厢号
        --top;
    }

    if (possible) {
        cout << "Possible" << endl;
    }

    return 0;
}
