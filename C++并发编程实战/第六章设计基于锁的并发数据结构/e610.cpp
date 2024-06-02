//使用锁和等待线程安全队列： try_pop和empty 
template<typename T>
class threadsafe_queue {
private:
    std::unique_ptr<node> try_pop_head() {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if (head.get() == get_tail())
            return std::unique_ptr<node>();
        return pop_head();
    }

    std::unique_ptr<node> try_pop_head(T& value) {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if (head.get() == get_tail())
            return std::unique_ptr<node>();
        value = std::move(*head->data);
        return pop_head();
    }

    // Assume there is a function `node* get_tail()` and `std::unique_ptr<node> pop_head()` declared above.
    // These functions are not shown in the image but are necessary for the code to work.

public:
    std::shared_ptr<T> try_pop() {
        std::unique_ptr<node> old_head = try_pop_head();
        return old_head ? old_head->data : std::shared_ptr<T>();
    }

    bool try_pop(T& value) {
        std::unique_ptr<node> const old_head = try_pop_head(value);
        return old_head != nullptr;
    }

    bool empty() {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        return (head.get() == get_tail());
    }
    
    // Assume there are also declarations for `head_mutex`, `head`, `get_tail()`, and `pop_head()`.
};
