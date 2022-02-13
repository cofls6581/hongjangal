#include <iostream>
#include <algorithm>

#define MAX 101

int row, col;
int matrix[MAX][MAX];
int tmp[MAX][MAX];

void copy() { // 연산 후 tmp에 저장된 결과를 matrix에 복사
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			matrix[i][j] = tmp[i][j];
}

void one() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			tmp[row - 1 - i][j] = matrix[i][j];
		}
	}
	copy();
}

void two() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			tmp[i][col - 1 - j] = matrix[i][j];
		}
	}
	copy();
}

void three() {
	int init_row = row;
	std::swap(row, col);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			tmp[i][j] = matrix[init_row - 1 - j][i];
		}
	}
	copy();
}

void four() {
	int init_col = col;
	std::swap(row, col);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			tmp[i][j] = matrix[j][init_col - 1 - i];
		}
	}
	copy();
}

void five() {
	int half_row = row / 2;
	int half_col = col / 2;
	
	// matrix 1그룹 -> tmp 2그룹
	for (int i = 0; i < half_row; ++i) {
		for (int j = 0; j < half_col; ++j) {
			tmp[i][j + half_col] = matrix[i][j];
		}
	 }
	// matrix 2그룹 -> tmp 3그룹
	for (int i = 0; i < half_row; ++i) {
		for (int j = 0; j < half_col; ++j) {
			tmp[i + half_row][j + half_col] = matrix[i][j + half_col];
		}
	}
	// matrix 3그룹 -> tmp 4그룹
	for (int i = 0; i < half_row; ++i) {
		for (int j = 0; j < half_col; ++j) {
			tmp[i + half_row][j] = matrix[i + half_row][j + half_col];
		}
	}
	// matrix 4그룹 -> tmp 1그룹
	for (int i = 0; i < half_row; ++i) {
		for (int j = 0; j < half_col; ++j) {
			tmp[i][j] = matrix[i + half_row][j];
		}
	}

	copy();
}

void six() {
	int half_row = row / 2;
	int half_col = col / 2;

	// matrix 1그룹 -> tmp 4그룹
	for (int i = 0; i < half_row; ++i) {
		for (int j = 0; j < half_col; ++j) {
			tmp[i + half_row][j] = matrix[i][j];
		}
	}
	// matrix 2그룹 -> tmp 1그룹
	for (int i = 0; i < half_row; ++i) {
		for (int j = 0; j < half_col; ++j) {
			tmp[i][j] = matrix[i][j + half_col];
		}
	}
	// matrix 3그룹 -> tmp 2그룹
	for (int i = 0; i < half_row; ++i) {
		for (int j = 0; j < half_col; ++j) {
			tmp[i][j + half_col] = matrix[i + half_row][j + half_col];
		}
	}
	// matrix 4그룹 -> tmp 3그룹
	for (int i = 0; i < half_row; ++i) {
		for (int j = 0; j < half_col; ++j) {
			tmp[i + half_row][j + half_col] = matrix[i + half_row][j];
		}
	}

	copy();
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	// 선언 및 입력
	int R;
	std::cin >> row >> col >> R;
	
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			std::cin >> matrix[i][j];

	// 문제 풀기
	for (int i = 0; i < R; ++i) {
		int num; std::cin >> num;

		if (num == 1) one();
		else if (num == 2) two();
		else if (num == 3) three();
		else if (num == 4) four();
		else if (num == 5) five();
		else if (num == 6) six();
	}

	// 출력 및 종료
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			std::cout << matrix[i][j] << ' ';
		std::cout << '\n';
	}

	return 0;
}
