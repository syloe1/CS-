#include <iostream>
#include <string>
#include <cmath>

// �������ڽ���������ת��Ϊ2���ݴη��ĺͣ���������Ӧ���ַ���
std::string toPowerOfTwo(int num) {
    if (num == 0) return "2(0)";
    if (num == 1) return "2+2(0)";
    std::string result;
    while (num > 0) {
        int power = static_cast<int>(log2(num));
        result = "2(" + toPowerOfTwo(num - (1 << power)) + ")+" + result;
        num = num - (1 << power);
    }
    // �Ƴ�β����"+"����
    if (!result.empty() && result.back() == '+') {
        result.pop_back();
    }
    return result;
}

// ������
int main() {
    int n;
    std::cin >> n;

    // ������nת��Ϊ2���ݴη��ĺ͵��ַ�����ʾ
    std::string representation = toPowerOfTwo(n);

    // ������
    std::cout << representation << std::endl;

    return 0;
}
