//scoped_thread��ʾ���÷�
class scoped_thread {
    std::thread t;
public:
    // 2.3 ת���̵߳�����Ȩ
    explicit scoped_thread(std::thread t) : t(std::move(t)) {
        if (!t.joinable())
            throw std::logic_error("No thread");
    }
    ~scoped_thread() {
        t.join();
    }
    scoped_thread(scoped_thread const&) = delete;
    scoped_thread& operator=(scoped_thread const&) = delete;

    struct func;
    // �μ��嵥 2.1
    void f() {
        int some_local_state;
        scoped_thread t(std::thread(func(some_local_state)));
        do_something_in_current_thread();
    }
}; 
