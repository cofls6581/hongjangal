#include <iostream>

#define MAX 301

int row, col;
int matrix[MAX][MAX];
int tmp[MAX][MAX];

void copy() { // 연산 후 tmp에 저장된 결과를 matrix에 복사
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			matrix[i][j] = tmp[i][j];
}

void counterClockWise() {
	int x1 = 0, y1 = 0;
	int x2 = row-1, y2 = 0;
	int x3 = row - 1, y3 = col - 1;
	int x4 = 0, y4 = col - 1;

	while ((x1 < x3) && (y1 < y3)) {
		for(int i = x4; i < x3; ++i) tmp[i][y4] = matrix[i + 1][y4];
		for(int j = y3; j > y2; --j) tmp[x3][j] = matrix[x3][j - 1];
		for(int i = x2; i > x1; --i) tmp[i][y2] = matrix[i - 1][y2];
		for(int j = y1; j < y4; ++j) tmp[x1][j] = matrix[x1][j + 1];

		x1++; y1++;
		x2--; y2++;
		x3--; y3--;
		x4++; y4--;
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
	while(R--) counterClockWise();

	// 출력 및 종료
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			std::cout << matrix[i][j] << ' ';
		std::cout << '\n';
	}

	return 0;
}
