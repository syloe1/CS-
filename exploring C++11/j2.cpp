//不修改数组找出重复的数字
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> findDuplicatesSorted(int arr[], int n) {
	std::vector<int> duplicates;
	if (n == 0) return duplicates;

	int slow = 0; // 慢指针
	while (slow < n - 1) {
		if (arr[slow] == arr[slow + 1]) {
			duplicates.push_back(arr[slow]);
			// 跳过重复的元素
			while (slow < n - 1 && arr[slow] == arr[slow + 1]) {
				++slow;
			}
		} else {
			++slow;
		}
	}
	return duplicates;
}

int main() {
	int arr[] = {1, 2, 3, 3, 4, 4, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]); // 计算数组中元素的数量

	// 正确使用 sort 函数对数组进行排序
	std::sort(arr, arr + n);

	std::vector<int> duplicates = findDuplicatesSorted(arr, n);

	if (!duplicates.empty()) {
		std::cout << "Duplicates found in sorted array: ";
		for (int num : duplicates) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	} else {
		std::cout << "No duplicates found." << std::endl;
	}

	return 0;
}
