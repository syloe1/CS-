//һ���̰߳�ȫջ�ĸ�Ҫ�ඨ��
#include <exception>
#include <memory>

struct empty_stack : std::exception {
    const char* what() const throw();
};

template<typename T>
class threadsafe_stack {
    // ��ֵ�������ɾ����
public:
    threadsafe_stack();
    threadsafe_stack(const threadsafe_stack&);
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;
    
    void push(T new_value);
    std::shared_ptr<T> pop();
    void pop(T& value);
    bool empty() const;
}; 
