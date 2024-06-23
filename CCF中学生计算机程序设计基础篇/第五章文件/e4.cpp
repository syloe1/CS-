#include <cstdio>
#include <algorithm>
#include <vector> // 需要包含这个头文件，因为使用了vector

int main() {
    FILE *fin, *fout;
    int N, a[1000001]; // 假设数组足够大以存储所有输入的整数

    // 打开输入文件
    fin = fopen("sort.in", "r");
    if (!fin) {
        perror("Error opening input file");
        return 1;
    }

    // 读取N的值
    fscanf(fin, "%d", &N);

    // 读取N个整数到数组a中
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &a[i]);
    }

    // 对数组a中的元素进行排序
    std::sort(a, a + N);

    // 打开输出文件
    fout = fopen("sort.out", "w");
    if (!fout) {
        perror("Error opening output file");
        fclose(fin); // 关闭输入文件
        return 1;
    }

    // 将排序后的数组写入到输出文件
    for (int i = 0; i < N; i++) {
        fprintf(fout, "%d ", a[i]); // 每个数字后面添加空格
    }

    // 关闭文件
    fclose(fin);
    fclose(fout);

    return 0;
}
