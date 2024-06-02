//atomic_flag������������ʵ��
#include <atomic>

class spinlock_mutex {
    std::atomic_flag flag;

public:
    spinlock_mutex() : flag(ATOMIC_FLAG_INIT) {
        // ���캯����ʵ�֣�����Ϊ��
    }

    void lock() {
        while (flag.test_and_set(std::memory_order_acquire)) {
            // ѭ��ֱ���ܹ��ɹ����ñ�־
        }
    }

    void unlock() {
        flag.clear(std::memory_order_release);
    }
};
