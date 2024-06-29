//数组 
#include <iostream>
#include <crtdbg.h> // 用于 _tmain 和 printf

int GetSize(int* data) {
    return sizeof(*data);
}

int main() {
    int dataI[] = {1, 2, 3, 4, 5};
    int sizeI = sizeof(dataI);
    int* data2 = dataI;
    int size2 = sizeof(data2); // 指针的大小，通常是 4 或 8 字节
    int size3 = GetSize(dataI); // 返回单个 int 的大小，通常是 4 字节

    printf("%d, %d, %d\n", sizeI, size2, size3);

    return 0;
}
