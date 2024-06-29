#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> data { 10, 42 };
    // 使用 std::ostream_iterator 来输出到 std::cout
    std::ostream_iterator<int> out(std::cout, " ");
    
    // 使用 std::copy 将 data 中的元素复制到 out
    std::copy(data.begin(), data.end(), out);
    
    // --out 操作没有实际意义，因为 std::ostream_iterator 不支持递减操作
    // 移除 --out 行

    return 0;
}
