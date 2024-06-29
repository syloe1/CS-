#include <iostream>

class generate_id {
public:
    generate_id() : counter_{0} {}
    long next_id() {
        if (counter_ >= max_counter_) {
            throw std::overflow_error("Counter overflow");
        }
        return static_cast<long>(++counter_) + prefix_;
    }

private:
    short counter_;
    static short prefix_;
    static short const max_counter_{32767};
};

// ��̬��Ա�����ĳ�ʼ��
short generate_id::prefix_ = 0;  // ����ǰ׺��0������Ը�����Ҫ�޸�

int main() {
    generate_id gen{}; // ����һ�� ID ������
    for (int i = 0; i != 10; ++i) {
        std::cout << gen.next_id() << '\n';
    }
    return 0;
}
