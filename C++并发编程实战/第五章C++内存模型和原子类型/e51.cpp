//atomic_flag的自旋锁互斥实现
#include <atomic>

class spinlock_mutex {
    std::atomic_flag flag;

public:
    spinlock_mutex() : flag(ATOMIC_FLAG_INIT) {
        // 构造函数的实现，可能为空
    }

    void lock() {
        while (flag.test_and_set(std::memory_order_acquire)) {
            // 循环直到能够成功设置标志
        }
    }

    void unlock() {
        flag.clear(std::memory_order_release);
    }
};
