//使用锁层次来避免死锁
 hierarchical_mutex high_level_mutex(10000);
hierarchical_mutex low_level_mutex(5000);

int do_low_level_stuff();

int low_level_func() {
    std::lock_guard<hierarchical_mutex> lk(low_level_mutex);
    return do_low_level_stuff();
}

void high_level_stuff(int some_param) {
    // 此处代码不完整，假设high_level_stuff函数体需要进一步的定义
}

void high_level_func() {
    std::lock_guard<hierarchical_mutex> lk(high_level_mutex);
    high_level_stuff(low_level_func());
}

void thread_a() {
    high_level_func();
}

hierarchical_mutex other_mutex(100);

int do_other_stuff();

void other_stuff() {
    high_level_func();
}

void thread_b() {
    std::lock_guard<hierarchical_mutex> lk(other_mutex);
    do_other_stuff();
}

