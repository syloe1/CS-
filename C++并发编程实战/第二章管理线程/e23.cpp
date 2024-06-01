class thread_guard {
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) : t(t) {}
    ~thread_guard() {
        if (t.joinable()) //һ���߳�ֻ��joinһ�� 
            t.join();  //
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

struct func;

void f() {
    int some_local_state = 0; // ���� 'o' �� '0' �Ĵ�������
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t); //����g���ȱ����٣��������������� �̱߳���� 
    do_something_in_current_thread(); //�߳�ִ�е�fĩβʱ�� �ֲ�����ᰴ�չ��캯�����������١� 
}
