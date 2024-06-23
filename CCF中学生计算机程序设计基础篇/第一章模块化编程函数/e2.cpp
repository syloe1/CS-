#include <iostream>
#include <vector>

// ����׳˵ĸ�������
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// ����������ĸ�������
unsigned long long combination(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// �����ƻ����������ķ�����
unsigned long long countApples(int M, int N) {
    return combination(M - 1 + N, N);
}

int main() {
    int t;
    std::cin >> t; // ��ȡ�������ݵ���Ŀ

    while (t--) {
        int M, N;
        std::cin >> M >> N; // ��ȡÿ������M��N

        unsigned long long K = countApples(M, N);
        std::cout << K << std::endl; // �����Ӧ��K
    }

    return 0;
}
