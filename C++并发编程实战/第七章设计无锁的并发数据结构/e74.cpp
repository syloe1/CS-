//当pop中没有线程时回收结点
 template<typename T>
class lock_free_stack {
private:
    // 原子变量
    std::atomic<unsigned> threads_in_pop;

    void try_reclaim(node* old_head); // 回收函数声明

public:
    std::shared_ptr<T> pop() {
        // ② 在做任何其他事情前增加计数
        ++threads_in_pop;
        node* old_head = head.load();
        while (old_head &&
               !head.compare_exchange_weak(old_head, old_head->next));
        std::shared_ptr<T> res;
        if (old_head) {
            // 如果可能，回收删除的结点
            res.swap(old_head->data);
            try_reclaim(old_head);
        }
        // 从结点中提取数据，而不是复制指针
        return res;
    }
};
