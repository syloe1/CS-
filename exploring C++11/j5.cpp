//ʵ��һ�������� ���ַ����е�ÿ��
#include <iostream>
#include <string>
#include <algorithm>

// �滻�ַ��������еĿո�Ϊ "%20"
void replaceSpacesWithPercentTwenty(std::string& str) {
    std::string result;
    result.reserve(str.size() * 3); // Ԥ�����㹻�Ŀռ䣬��ֹ������·���
    for (char ch : str) {
        if (ch == ' ') {
            result += "%20"; // �ո��滻Ϊ "%20"
        } else {
            result += ch; // �ǿո��ַ�ֱ����ӵ������
        }
    }
    str = result; // ���¹������ַ����滻ԭ�ַ���
}

int main() {
    std::string myString = "We are happy";
    replaceSpacesWithPercentTwenty(myString);

    std::cout << "Original string: " << myString << std::endl;
    return 0;
}
