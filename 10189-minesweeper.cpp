#include <iostream>
#include <vector>


int main()
{
	int row, col;
	int field = 0;
	while (std::cin >> row >> col) {
		if (row == 0 || col == 0) {
			break;
		}
		field++;

		if (field != 1) {
			std::cout << '\n';
		}
		std::cout << "Field #" << field << ":\n";

		std::vector<std::vector<char>> matrix(row, std::vector<char>(col, '.'));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				std::cin >> matrix[i][j];
			}
		}

		// fill
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] == '*') {
					continue;
				}
				int north = (i-1 >= 0 && matrix[i-1][j] == '*') ? 1 : 0;
				int south = (i+1 < row && matrix[i+1][j] == '*') ? 1 : 0;
				int east = (j+1 < col && matrix[i][j+1] == '*') ? 1 : 0;
				int west = (j-1 >= 0 && matrix[i][j-1] == '*') ? 1 : 0;

				int northeast = (i-1 >= 0 && j+1 < col && matrix[i-1][j+1] == '*') ? 1 : 0;
				int northwest = (i-1 >= 0 && j-1 >= 0 && matrix[i-1][j-1] == '*') ? 1 : 0;
				int southeast = (i+1 < row && j+1 < col && matrix[i+1][j+1] == '*') ? 1 : 0;
				int southwest = (i+1 < row && j-1 >= 0 && matrix[i+1][j-1] == '*') ? 1 : 0;

				int count = north + south + east + west + northeast + northwest + southeast + southwest;
				matrix[i][j] = '0' + count;
			}
		}

		// print
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				std::cout << matrix[i][j];
			}
			std::cout << '\n';
		}
	}
	return 0;
}
