//���������������a1��a2, �ڴ���a1��ĩβ���㹻��Ŀ���ռ�����a2. ��ʵ��һ��
//������ ��a2�е��������ֲ���a1�У� �������е������������ 
#include <iostream>
#include <vector>

// �ϲ��������������飬a1 ���㹻�Ŀռ������� a2
void mergeSortedArrays(std::vector<int>& a1, const std::vector<int>& a2) {
    int i = a1.size() - 1; // a1 ��ĩβ����
    int j = a2.size() - 1; // a2 ��ĩβ����
    int k = i + j; // �ϲ��������ĩβ����

    // �Ӻ���ǰ������ֱ�� k ���� a1 �Ŀ�ʼλ��
    while (k >= 0) {
        if (j < 0 || (i >= 0 && a1[i] > a2[j])) {
            a1[k] = a1[i]; // �� a1 �е�Ԫ�طŵ���ȷ��λ��
            i--;
        } else {
            a1[k] = a2[j]; // �� a2 �е�Ԫ�طŵ���ȷ��λ��
            j--;
        }
        k--;
    }
}

int main() {
    std::vector<int> a1 = {1, 3, 5, 7, 0, 0, 0}; // �����������㹻�ռ�
    std::vector<int> a2 = {2, 4, 6, 8};

    mergeSortedArrays(a1, a2);

    std::cout << "Merged array: ";
    for (int num : a1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
