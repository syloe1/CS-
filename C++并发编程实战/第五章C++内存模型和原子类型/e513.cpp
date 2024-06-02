//在非原子操作上强制顺序
 #include <atomic>
#include <thread>
#include <cassert>

// x现在是一个普通的非原子变量
bool x = false;
std::atomic<bool> y;
std::atomic<int> z;

void write_x_then_y()
{
    // ①在屏障前存储x
    x = true;
    std::atomic_thread_fence(std::memory_order_release);
    // ②在屏障后存储y
    y.store(true, std::memory_order_relaxed);
}

void read_y_then_x()
{
    // ③此断言不会触发
    while(!y.load(std::memory_order_relaxed));
    std::atomic_thread_fence(std::memory_order_acquire);
    if(x)
        // ④将读取#1写入的值
        ++z;
}

int main()
{
    x = false;
    y = false;
    z = 0;

    std::thread a(write_x_then_y);
    std::thread b(read_y_then_x);

    a.join();
    b.join();

    // 断言z.load() != 0
    assert(z.load() != 0);
}
