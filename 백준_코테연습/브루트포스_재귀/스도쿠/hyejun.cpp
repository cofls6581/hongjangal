#include <iostream>

using namespace std;

int board[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

// 행, 열, 대각선에 대해서 bool형 배열을 만들어서 해당 숫자가 있으면 true를 저장.

int getSquare(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

void solve(int n) { // n번째 칸 = x행 * 9 + y열
	// 성공한 경우
	if (n == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	// 다음 호출 (조건 검사)
	int x = n / 9;
	int y = n % 9;
	if (board[x][y] != 0) { // 빈칸이 아니라면 다음 칸으로 넘어가기
		solve(n + 1);
	}
	else { // 빈칸이라면
		for (int i = 1; i <= 9; i++) {
			if (row[x][i] == false && col[y][i] == false && square[getSquare(x, y)][i] == false) { // 조건 검사
				// 호출 전 준비
				row[x][i] = col[y][i] = square[getSquare(x, y)][i] = true;
				board[x][y] = i;
				// 호출
				solve(n + 1);
				// 호출 후 복구
				row[x][i] = col[y][i] = square[getSquare(x, y)][i] = false;
				board[x][y] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			row[i][board[i][j]] = true;
			col[j][board[i][j]] = true;
			square[getSquare(i, j)][board[i][j]] = true;
		}
	}
	solve(0);
	return 0;
}
