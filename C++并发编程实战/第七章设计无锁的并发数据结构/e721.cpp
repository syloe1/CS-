//无锁队列使用帮助的push
 template<typename T>
class lock_free_queue {
private:
    // ... (other private members and methods)

    void set_new_tail(counted_node_ptr old_tail, counted_node_ptr const& new_tail) {
        node* const current_tail_ptr = old_tail.ptr;
        while (!tail.compare_exchange_weak(old_tail, new_tail) &&
               old_tail.ptr == current_tail_ptr) {
            free_external_counter(old_tail);
            else {
                current_tail_ptr->release_ref();
            }
        }
    }

public:
    // ... (other public members and methods)

    void push(T new_value) {
        std::unique_ptr<T> new_data(new T(new_value));
        counted_node_ptr new_next;
        new_next.ptr = new node;
        new_next.external_count = 1;

        counted_node_ptr old_tail = tail.load();
        for (;;) {
            increase_external_count(tail, old_tail);
            T* old_data = nullptr;
            if (old_tail.ptr->data.compare_exchange_strong(
                old_data, new_data.get())) {
                counted_node_ptr old_next = nullptr;
                if (old_tail.ptr->next.compare_exchange_strong(
                    old_next, new_next)) {
                    delete new_next.ptr;
                    new_next = old_next;
                    set_new_tail(old_tail, new_data.release());
                    break;
                } else {
                    if (old_tail.ptr->next.compare_exchange_weak(
                            counted_node_ptr(old_next, new_next))) {
                        // ... (rest of the code for this branch is not shown)
                    }
                }
            }
        }
    }
};
