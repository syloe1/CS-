//���� 
#include <iostream>
#include <crtdbg.h> // ���� _tmain �� printf

int GetSize(int* data) {
    return sizeof(*data);
}

int main() {
    int dataI[] = {1, 2, 3, 4, 5};
    int sizeI = sizeof(dataI);
    int* data2 = dataI;
    int size2 = sizeof(data2); // ָ��Ĵ�С��ͨ���� 4 �� 8 �ֽ�
    int size3 = GetSize(dataI); // ���ص��� int �Ĵ�С��ͨ���� 4 �ֽ�

    printf("%d, %d, %d\n", sizeI, size2, size3);

    return 0;
}
