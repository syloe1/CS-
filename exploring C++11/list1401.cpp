#include <cstdio>
#include <fstream>
#include <iostream>

int main() {
    // ����1: ʹ��˫��б��
    std::ifstream in{"C:\\Users\\Administrator\\Desktop\\׼��\\explorec++11\\1.txt"};
    
    // ����2: ʹ��ԭʼ�ַ���������
    // std::ifstream in{R"(C:\Users\Administrator\Desktop\׼��\explorec++11\1.txt)"};

    if (!in) {
        std::perror("Error opening file");
    } else {
        int x{};
        while (in >> x) {
            std::cout << x << '\n';
        }
        in.close();
    }
    return 0;
}
