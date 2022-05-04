#include <iostream>
#include <cmath>

using namespace std;

int N;
bool board[15][15];
bool check_col[15], check_diag1[31], check_diag2[31]; // diag1: / , diag2: \

bool check(int row, int col) {
	if (check_col[col] == true) return false;
	if (check_diag1[row + col] == true) return false;
	if (check_diag2[row - col + N] == true) return false;
	return true;
}

int calc(int row) { // row 행에서 퀸을 어디에 놓을지 결정
	// 성공한 경우
	if (row == N) {
		return 1;
	}
	// 실패한 경우 코드 대신, '다음 호출'시 조건을 검사함. (같은 열, 대각선에 퀸이 있는 경우 다음 호출 X)
	// 다음 호출
	int ans = 0;
	for (int col = 0; col < N; col++) {
		if (check(row, col)) {
			check_col[col] = true;
			check_diag1[row + col] = true;
			check_diag2[row - col + N] = true;
			board[row][col] = true;

			ans += calc(row + 1);

			check_col[col] = false;
			check_diag1[row + col] = false;
			check_diag2[row - col + N] = false;
			board[row][col] = false;

		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	cout << calc(0) << '\n';
	return 0;
}
