/*
找数。给一个长度为n的单调增的正整数序列，即序列中
每一个数都比前一个数大。有m个询问，每次询问一个x，问序列中最后
一个小于等于x的数是什么？
输入格式：第1行，两个整数n,m；接下来一行n个数，表示这个序列；
接下来m行每行一个数，表示一个询问。
输出格式：输出共m行，表示序列中最后一个小于等于x的数是什么。
假如没有，则输出-1
*/ 
#include <iostream>
using namespace std;

const int MAXN = 110000; // 定义数组的最大大小
int n, m, a[MAXN];      // 定义数组a的大小为MAXN

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i]; // 读取数组元素
    a[0] = -1; // 将数组的第一个元素设为负数，作为二分查找的哨兵

    for (int i = 1; i <= m; i++) {
        int X;
        int left = 1, right = n, mid;
        cin >> X; // 读取要查找的值X

        while (left <= right) {
            mid = left + (right - left) / 2; // 避免溢出，使用这种写法计算mid
            if (a[mid] < X) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // 输出大于等于X的最小元素的索引
        // 如果left > n，说明没有找到合适的元素，需要处理这种情况
        if (left <= n) {
            cout << a[left] << endl;
        } else {
            cout << "No element found" << endl; // 没有找到合适的元素
        }
    }

    return 0;
}
