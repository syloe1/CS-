#include <iostream>
#include <vector>

// 计算阶乘的辅助函数
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// 计算组合数的辅助函数
unsigned long long combination(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// 计算放苹果到盘子里的方法数
unsigned long long countApples(int M, int N) {
    return combination(M - 1 + N, N);
}

int main() {
    int t;
    std::cin >> t; // 读取测试数据的数目

    while (t--) {
        int M, N;
        std::cin >> M >> N; // 读取每组数据M和N

        unsigned long long K = countApples(M, N);
        std::cout << K << std::endl; // 输出相应的K
    }

    return 0;
}
