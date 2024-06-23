/*
这种“炸弹”利用最先进的量子物理技术，爆
炸后产生的冲击波可以完全清除波及范围内的所有垃圾，并且不会产生任
何其他不良影响。炸弹爆炸后冲击波是以正方形方式扩散的，炸弹威力（扩
散距离）以d给出，表示可以传播d条街道。
*/
#include <iostream>
using namespace std;
const int MAXN = 1030;

int cnt[MAXN][MAXN], n, d;

void work() {
    // 初始化二维数组
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            cnt[i][j] = 0;
        }
    }

    cin >> d;
    cin >> n;

    // 读取每个点的坐标和长度
    for (int i = 1; i <= n; i++) {
        int x, y, l;
        cin >> x >> y >> l;

        // 计算点 (x, y) 周围半径为 d 的点的累加长度
        for (int xr = -d; xr <= d; xr++) {
            if (x + xr >= 0 && x + xr < MAXN) {
                for (int yr = -d; yr <= d; yr++) {
                    if (y + yr >= 0 && y + yr < MAXN) {
                        cnt[x + xr][y + yr] += l;
                    }
                }
            }
        }
    }

    // 找出累加长度的最大值及其出现次数
    int maxval = -1, num = 0;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (cnt[i][j] > maxval) {
                maxval = cnt[i][j];
                num = 1;
            } else if (cnt[i][j] == maxval) {
                num++;
            }
        }
    }

    // 输出结果
    cout << num << " " << maxval << endl;
}

int main() {
    work();
    return 0;
}
