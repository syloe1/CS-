//反向输出reverse
 #include <cstdio>
#include <algorithm>
using namespace std;

int N, a[1000001]; // 定义数组a来存储输入的整数

int main() {
    // 重定向只读文件reverse.in到stdin
    freopen("reverse.in", "r", stdin);
    // 重定向只写文件reverse.out到stdout
    freopen("reverse.out", "w", stdout);

    // 使用标准输入scanf读取N的值
    scanf("%d", &N);
    // 读取N个整数到数组a中
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    // 逆序输出数组a中的元素到标准输出
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", a[i]); // 使用printf来输出，每个数字后面添加空格
    }

    // 无需关闭标准输入输出流，因为它们是全局的
    return 0;
}
