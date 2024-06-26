//缺少节点的无锁栈
template<typename T>
class lock_free_stack {
private:
    struct node {
        std::shared_ptr<T> data;  // ① data现在由指针持有
        node* next;

        node(T const& data_) : data(std::make_shared<T>(data_)) {}
    };

    std::atomic<node*> head;

public:
    void push(T const& data) {
        node* const new_node = new node(data);
        new_node->next = head.load();
        while (!head.compare_exchange_weak(new_node->next, new_node));
    }

    std::shared_ptr<T> pop() {
        node* old_head = head.load();
        while (old_head && 
               !head.compare_exchange_weak(old_head, old_head->next)) {
            // 循环直到能够成功更新头指针
        }
        return old_head ? old_head->data : std::shared_ptr<T>();
    }
};
