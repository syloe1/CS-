#include <cassert>
#include <cmath> // ���� std::fabs

int main() {
    float a {0.03F};
    float b {10.0F};
    float c {0.3F};
    const float epsilon = 1e-5F; // ����һ��С�����̶�
    assert(std::fabs(a * b - c) < epsilon); // ʹ�����̶ȼ��
}
