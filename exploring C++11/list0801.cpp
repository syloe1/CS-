#include <iostream>
#include <iomanip> // ����ʹ���Ʊ���ȹ���

int main() {
    // ʹ�� C++11 ���б��ʼ���﷨��ʼ��һ���ַ���������
    std::string header = " N   N^2    N^3\n";
    std::cout << header;
    
    // ���ڷ�Χ�� for ѭ����C++11 ���������
    for (auto i = 1; i != 21; ++i) {
        // ʹ�� C++11 �� auto �ؼ��ֽ��������Ƶ�
        auto square = i * i;
        auto cube = i * i * i;
        
        // ʹ�� << �������������
        std::cout << std::setw(4) << i << '\t' 
                  << std::setw(4) << square << '\t' 
                  << std::setw(4) << cube << '\n';
    }
    return 0;
}
