//�ڷ�ԭ�Ӳ�����ǿ��˳��
 #include <atomic>
#include <thread>
#include <cassert>

// x������һ����ͨ�ķ�ԭ�ӱ���
bool x = false;
std::atomic<bool> y;
std::atomic<int> z;

void write_x_then_y()
{
    // ��������ǰ�洢x
    x = true;
    std::atomic_thread_fence(std::memory_order_release);
    // �������Ϻ�洢y
    y.store(true, std::memory_order_relaxed);
}

void read_y_then_x()
{
    // �۴˶��Բ��ᴥ��
    while(!y.load(std::memory_order_relaxed));
    std::atomic_thread_fence(std::memory_order_acquire);
    if(x)
        // �ܽ���ȡ#1д���ֵ
        ++z;
}

int main()
{
    x = false;
    y = false;
    z = 0;

    std::thread a(write_x_then_y);
    std::thread b(read_y_then_x);

    a.join();
    b.join();

    // ����z.load() != 0
    assert(z.load() != 0);
}
