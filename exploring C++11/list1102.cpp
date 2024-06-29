#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> data { 10, 42 };
    // ʹ�� std::ostream_iterator ������� std::cout
    std::ostream_iterator<int> out(std::cout, " ");
    
    // ʹ�� std::copy �� data �е�Ԫ�ظ��Ƶ� out
    std::copy(data.begin(), data.end(), out);
    
    // --out ����û��ʵ�����壬��Ϊ std::ostream_iterator ��֧�ֵݼ�����
    // �Ƴ� --out ��

    return 0;
}
