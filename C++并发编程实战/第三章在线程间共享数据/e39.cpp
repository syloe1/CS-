//在交换操作中使用lock()和unique_lock() 
class some_big_object {
    // 假设这个类有相应的实现
};

void swap(some_big_object& lhs, some_big_object& rhs) {
    // 假设这是一个交换两个 some_big_object 对象的函数
}

class x {
private:
    some_big_object some_detail;
    std::mutex m;

public:
    x(some_big_object const& sd) : some_detail(sd) {}

    // 友元函数声明，允许访问类的私有成员
    friend void swap(x& lhs, x& rhs);
};

void swap(x& lhs, x& rhs) {
    if (&lhs == &rhs)
        return;

    // 使用 std::unique_lock 和 std::defer_lock 来手动锁定 mutex
    std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock);
    std::unique_lock<std::mutex> lock_b(rhs.m, std::defer_lock);
    std::lock(lock_a, lock_b); // 锁定两个 mutex

    // 交换两个 x 对象中的 some_detail 成员
    swap(lhs.some_detail, rhs.some_detail);

    // mutex 在这里会自动解锁，因为 std::unique_lock 遵守 RAII 原则
}
