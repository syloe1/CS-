//使用memory_order_consume同步数据
#include <atomic>
#include <thread>
#include <chrono>
#include <cassert>
#include <string>

struct X {
    int i;
    std::string s;
};

std::atomic<X*> p;
std::atomic<int> a;

void create_x() {
    X* x = new X;
    x->i = 42;
    x->s = "hello";
    a.store(99, std::memory_order_relaxed);
    p.store(x, std::memory_order_release);
}

void use_x() {
    X* x;
    while(!(x = p.load(std::memory_order_consume))) {
        std::this_thread::sleep(std::chrono::microseconds(1));
    }
    assert(x->i == 42);
    assert(x->s == "hello");
    assert(a.load(std::memory_order_relaxed) == 99);
}

int main() {
    std::thread t1(create_x);
    std::thread t2(use_x);
    t1.join();
    t2.join();
    return 0;
}
