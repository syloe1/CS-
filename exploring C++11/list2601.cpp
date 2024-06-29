#include <cassert>
#include <cmath> // 用于 std::fabs

int main() {
    float a {0.03F};
    float b {10.0F};
    float c {0.3F};
    const float epsilon = 1e-5F; // 定义一个小的容忍度
    assert(std::fabs(a * b - c) < epsilon); // 使用容忍度检查
}
