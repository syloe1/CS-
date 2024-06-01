class thread_guard {
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) : t(t) {}
    ~thread_guard() {
        if (t.joinable()) //一个线程只能join一次 
            t.join();  //
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

struct func;

void f() {
    int some_local_state = 0; // 假设 'o' 是 '0' 的错误输入
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t); //对象g首先被销毁，并且析构函数中 线程被结合 
    do_something_in_current_thread(); //线程执行到f末尾时， 局部对象会按照构造函数的逆序被销毁。 
}
