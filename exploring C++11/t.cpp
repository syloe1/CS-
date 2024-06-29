#include <iostream>

class generate_id {
public:
    generate_id() : counter_{0} {}
    long next_id() {
        if (counter_ >= max_counter_) {
            throw std::overflow_error("Counter overflow");
        }
        return static_cast<long>(++counter_) + prefix_;
    }

private:
    short counter_;
    static short prefix_;
    static short const max_counter_{32767};
};

// 静态成员变量的初始化
short generate_id::prefix_ = 0;  // 假设前缀是0，你可以根据需要修改

int main() {
    generate_id gen{}; // 创建一个 ID 生成器
    for (int i = 0; i != 10; ++i) {
        std::cout << gen.next_id() << '\n';
    }
    return 0;
}
