#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
    std::vector<int> data;
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(data));
    
    // 排序向量
    std::sort(data.begin(), data.end());
    
    // 移除重复项
    auto last = std::unique(data.begin(), data.end());
    data.erase(last, data.end());
    
    // 断言检查是否有序
    for (auto it = std::next(data.begin()); it != data.end(); ++it) {
        assert(*std::prev(it) <= *it);
    }
    
    // 打印结果
    std::cout << "{";
    for (const auto& v : data) {
        std::cout << (&v == &*data.begin() ? "" : ", ") << v;
    }
    std::cout << "}" << std::endl;
    
    return 0;
}
