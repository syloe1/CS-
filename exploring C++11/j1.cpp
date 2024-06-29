//找到长度为n的数组中重复的数字。  
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> 
//bool findDuplicates(int arr[], int n, std::vector<int>& duplicates) {
//    std::unordered_set<int> seen;
//    for (int num : arr) {
//        if (seen.find(num) != seen.end()) {
//            duplicates.push_back(num);
//        } else {
//            seen.insert(num);
//        }
//    }
//    return !duplicates.empty();
//}
bool findDuplicates(int arr[], int n, std::vector<int>& duplicates) {
    // 检查数组长度至少为2，否则无法有重复
    if (n < 2) return false;

    // 对数组进行排序
    std::sort(arr, arr + n);

    // 遍历排序后的数组查找重复项
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] == arr[i + 1]) {
            duplicates.push_back(arr[i]);
        }
    }
    return !duplicates.empty();
}


int main() {
    int arr[] = {1, 2, 3, 4, 2, 6, 7, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> duplicates;

    if (findDuplicates(arr, n, duplicates)) {
        std::cout << "Duplicates found: ";
        for (int num : duplicates) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No duplicates found." << std::endl;
    }

    return 0;
}
