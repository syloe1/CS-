//��pop��û���߳�ʱ���ս��
 template<typename T>
class lock_free_stack {
private:
    // ԭ�ӱ���
    std::atomic<unsigned> threads_in_pop;

    void try_reclaim(node* old_head); // ���պ�������

public:
    std::shared_ptr<T> pop() {
        // �� �����κ���������ǰ���Ӽ���
        ++threads_in_pop;
        node* old_head = head.load();
        while (old_head &&
               !head.compare_exchange_weak(old_head, old_head->next));
        std::shared_ptr<T> res;
        if (old_head) {
            // ������ܣ�����ɾ���Ľ��
            res.swap(old_head->data);
            try_reclaim(old_head);
        }
        // �ӽ������ȡ���ݣ������Ǹ���ָ��
        return res;
    }
};
