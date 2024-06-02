//意外地传出对受保护数据地引用
class some_data {
    int a;
    std::string b;
public:
    void do_something();
};

class data_wrapper {
private:
    some_data data;
    std::mutex m;
public:
    template<typename Function>
    void process_data(Function func) {
        std::lock_guard<std::mutex> lock(m);
        func(data);
    }
};

some_data* unprotected;
void malicious_function(some_data& protected_data) {
    unprotected = &protected_data;
}

data_wrapper x;
void foo() {
    // 传入一个函数
    x.process_data(malicious_function);
    unprotected->do_something();
} 
