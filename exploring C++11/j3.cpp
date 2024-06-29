//二维数组左右递增 上下递增。 完成一个函数 和一个整数， 判断数组中是否有该整数
#include <iostream>
#include <vector>

bool findInIncreasing2DArray(const std::vector<std::vector<int>>& matrix, int target) {
	if (matrix.empty()) return false;

	int rows = matrix.size();
	int cols = matrix[0].size();
	int row = 0;
	int col = cols - 1; // 从右上角开始

	while (row < rows && col >= 0) {
		if (matrix[row][col] == target) {
			return true; // 找到目标整数
		} else if (matrix[row][col] > target) {
			col--; // 当前元素太大，向左移动
		} else {
			row++; // 当前元素太小，向下移动
		}
	}

	return false; // 未找到目标整数
}

int main() {
	std::vector<std::vector<int>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	int target = 12;

	if (findInIncreasing2DArray(matrix, target)) {
		std::cout << "Number " << target << " found in the matrix." << std::endl;
	} else {
		std::cout << "Number " << target << " not found in the matrix." << std::endl;
	}

	return 0;
}

