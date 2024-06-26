//使用获取和释放的传递性同步
#include <atomic>
#include <thread>
#include <cassert>

std::atomic<int> data[5];
std::atomic<bool> sync1(false), sync2(false);

void thread_1() {
	data[0].store(42, std::memory_order_relaxed);
	data[1].store(97, std::memory_order_relaxed);
	data[2].store(17, std::memory_order_relaxed);
	data[3].store(-141, std::memory_order_relaxed);
	data[4].store(2003, std::memory_order_relaxed);
	// ①设置sync1
	sync1.store(true, std::memory_order_release);
}

void thread_2() {
	// ②循环直到sync1被设置
	while(!sync1.load(std::memory_order_acquire));
	// ③设置sync2
	sync2.store(true, std::memory_order_release);
}

void thread_3() {
	// 循环直到sync2被设置
	while(!sync2.load(std::memory_order_acquire));
	// 断言以验证数据
	assert(data[0].load(std::memory_order_relaxed) == 42);
	assert(data[1].load(std::memory_order_relaxed) == 97);
	assert(data[2].load(std::memory_order_relaxed) == 17);
	assert(data[3].load(std::memory_order_relaxed) == -141);
	assert(data[4].load(std::memory_order_relaxed) == 2003);
}
