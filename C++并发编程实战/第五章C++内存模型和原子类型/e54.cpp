//˳��һ������������˳��
#include <atomic>
#include <thread>
#include <cassert>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x() {
    x.store(true, std::memory_order_seq_cst);
}

void write_y() {
    // ��������δ��������Ŀ�����޸� y ��ֵ
}

void read_x_then_y() {
    while (!x.load(std::memory_order_seq_cst)) {
        // ѭ��ֱ�� x Ϊ true
    }
    if (y.load(std::memory_order_seq_cst)) {
        // ��������ʱִ��
        // ���벻����������ȱ�ٶ� z �Ĳ���
    }
}

void read_y_then_x() {
    while (!y.load(std::memory_order_seq_cst)) {
        // ѭ��ֱ�� y Ϊ true
    }
    if (x.load(std::memory_order_seq_cst)) {
        // ��������ʱִ��
        // ���벻����������ȱ�ٶ� z �Ĳ���
    }
}

int main() {
    x = false;
    y = false;
    z = 0;

    std::thread a(write_x);
    std::thread b(write_y);
    std::thread c(read_x_then_y);
    std::thread d(read_y_then_x);

    a.join();
    b.join();
    c.join();
    d.join();

    assert(z.load() == 0); // ȷ�� z ��ֵ����Ԥ��

    return 0; // ����������ֵ������ȱ��
} 
