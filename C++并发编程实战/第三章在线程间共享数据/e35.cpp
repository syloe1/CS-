//一个线程安全栈的详细类定义
 #include <exception>
#include <memory>
#include <mutex>
#include <stack>

struct empty_stack : std::exception {
    const char* what() const throw();
};

template<typename T>
class threadsafe_stack {
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    threadsafe_stack()() // 此处的构造函数声明可能有误，通常不需要两个括号
    threadsafe_stack(const threadsafe_stack& other) {
        std::lock_guard<std::mutex> lock(other.m);
        // 在构造函数体中执行复制
        data = other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }

    std::shared_ptr<T> pop() {
        // 在试着出栈值的时候检查是否为空
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw empty_stack();
        // 在修改栈之前分配返回值
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }

    void pop(T& value) {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw empty_stack();
        value = data.top();
        data.pop();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};
