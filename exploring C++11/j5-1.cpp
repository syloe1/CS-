//有两个排序的数组a1和a2, 内存在a1的末尾有足够多的空余空间容纳a2. 请实现一个
//函数， 把a2中的所有数字插入a1中， 并且所有的数字是排序的 
#include <iostream>
#include <vector>

// 合并两个已排序数组，a1 有足够的空间来容纳 a2
void mergeSortedArrays(std::vector<int>& a1, const std::vector<int>& a2) {
    int i = a1.size() - 1; // a1 的末尾索引
    int j = a2.size() - 1; // a2 的末尾索引
    int k = i + j; // 合并后数组的末尾索引

    // 从后向前遍历，直到 k 到达 a1 的开始位置
    while (k >= 0) {
        if (j < 0 || (i >= 0 && a1[i] > a2[j])) {
            a1[k] = a1[i]; // 将 a1 中的元素放到正确的位置
            i--;
        } else {
            a1[k] = a2[j]; // 将 a2 中的元素放到正确的位置
            j--;
        }
        k--;
    }
}

int main() {
    std::vector<int> a1 = {1, 3, 5, 7, 0, 0, 0}; // 假设这里有足够空间
    std::vector<int> a2 = {2, 4, 6, 8};

    mergeSortedArrays(a1, a2);

    std::cout << "Merged array: ";
    for (int num : a1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
