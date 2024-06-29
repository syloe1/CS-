//��ά�������ҵ��� ���µ����� ���һ������ ��һ�������� �ж��������Ƿ��и�����
#include <iostream>
#include <vector>

bool findInIncreasing2DArray(const std::vector<std::vector<int>>& matrix, int target) {
	if (matrix.empty()) return false;

	int rows = matrix.size();
	int cols = matrix[0].size();
	int row = 0;
	int col = cols - 1; // �����Ͻǿ�ʼ

	while (row < rows && col >= 0) {
		if (matrix[row][col] == target) {
			return true; // �ҵ�Ŀ������
		} else if (matrix[row][col] > target) {
			col--; // ��ǰԪ��̫�������ƶ�
		} else {
			row++; // ��ǰԪ��̫С�������ƶ�
		}
	}

	return false; // δ�ҵ�Ŀ������
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

