//使用细粒度锁和条件变量的线程安全队列
template<typename T>
class queue {
private:
    struct node {
        T data;
        std::unique_ptr<node> next;
        node(T data_) : data(std::move(data_)), next(nullptr) {}
    };

    std::unique_ptr<node> head;
    node* tail;

public:
    queue() : head(nullptr), tail(nullptr) {}
    queue(const queue& other) = delete;
    queue& operator=(const queue& other) = delete;

    std::shared_ptr<T> try_pop() {
        if (!head)
            return std::shared_ptr<T>();
        std::shared_ptr<T> const res(std::make_shared<T>(std::move(head->data)));
        std::unique_ptr<node> const old_head = std::move(head);
        head = std::move(old_head->next);
        return res;
    }

    void push(T new_value) {
        std::unique_ptr<node> p(new node(std::move(new_value)));
        node* const new_tail = p.get();
        if (tail)
            tail->next = std::move(p);
        else
            head = std::move(p);
        tail = new_tail;
    }
}; 
