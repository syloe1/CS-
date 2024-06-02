//顺序一致隐含着总体顺序
#include <atomic>
#include <thread>
#include <cassert>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x() {
    x.store(true, std::memory_order_seq_cst);
}

void write_y() {
    // 函数内容未给出，但目的是修改 y 的值
}

void read_x_then_y() {
    while (!x.load(std::memory_order_seq_cst)) {
        // 循环直到 x 为 true
    }
    if (y.load(std::memory_order_seq_cst)) {
        // 条件满足时执行
        // 代码不完整，可能缺少对 z 的操作
    }
}

void read_y_then_x() {
    while (!y.load(std::memory_order_seq_cst)) {
        // 循环直到 y 为 true
    }
    if (x.load(std::memory_order_seq_cst)) {
        // 条件满足时执行
        // 代码不完整，可能缺少对 z 的操作
    }
}

int main() {
    x = false;
    y = false;
    z = 0;

    std::thread a(write_x);
    std::thread b(write_y);
    std::thread c(read_x_then_y);
    std::thread d(read_y_then_x);

    a.join();
    b.join();
    c.join();
    d.join();

    assert(z.load() == 0); // 确保 z 的值符合预期

    return 0; // 主函数返回值，可能缺少
} 
