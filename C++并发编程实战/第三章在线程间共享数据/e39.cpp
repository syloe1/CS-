//�ڽ���������ʹ��lock()��unique_lock() 
class some_big_object {
    // �������������Ӧ��ʵ��
};

void swap(some_big_object& lhs, some_big_object& rhs) {
    // ��������һ���������� some_big_object ����ĺ���
}

class x {
private:
    some_big_object some_detail;
    std::mutex m;

public:
    x(some_big_object const& sd) : some_detail(sd) {}

    // ��Ԫ��������������������˽�г�Ա
    friend void swap(x& lhs, x& rhs);
};

void swap(x& lhs, x& rhs) {
    if (&lhs == &rhs)
        return;

    // ʹ�� std::unique_lock �� std::defer_lock ���ֶ����� mutex
    std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock);
    std::unique_lock<std::mutex> lock_b(rhs.m, std::defer_lock);
    std::lock(lock_a, lock_b); // �������� mutex

    // �������� x �����е� some_detail ��Ա
    swap(lhs.some_detail, rhs.some_detail);

    // mutex ��������Զ���������Ϊ std::unique_lock ���� RAII ԭ��
}
