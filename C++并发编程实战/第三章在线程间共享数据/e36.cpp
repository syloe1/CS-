//在交换操作中使用lock()和lock_guard()
class some_big_object;

void swap(some_big_object& lhs, some_big_object& rhs);

class x {
private:
    some_big_object some_detail;
    std::mutex m;

public:
    x(some_big_object const& sd) : some_detail(sd) {}
    friend void swap(x& lhs, x& rhs) {
        if (&lhs == &rhs)
            return;
        
        std::lock(lhs.m, rhs.m);
        std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
        std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
        swap(lhs.some_detail, rhs.some_detail);
    }
};


