//һ���̰߳�ȫջ����ϸ�ඨ��
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
    threadsafe_stack()() // �˴��Ĺ��캯��������������ͨ������Ҫ��������
    threadsafe_stack(const threadsafe_stack& other) {
        std::lock_guard<std::mutex> lock(other.m);
        // �ڹ��캯������ִ�и���
        data = other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }

    std::shared_ptr<T> pop() {
        // �����ų�ջֵ��ʱ�����Ƿ�Ϊ��
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw empty_stack();
        // ���޸�ջ֮ǰ���䷵��ֵ
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
