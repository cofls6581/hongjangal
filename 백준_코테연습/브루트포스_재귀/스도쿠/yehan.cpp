#include <iostream>

using namespace std;

int board[9][9];
bool row[9][10]; // i행에 숫자 j가 있으면 true
bool col[9][10]; // i열에 숫자 j가 있으면 true
bool square[9][10]; // i번 칸에 숫자 j가 있으면 true

int getSquare(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

void solve(int n) {
	// 정답을 찾은 경우
	if (n == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	// 다음 경우
	int x = n / 9;
	int y = n % 9;
	if (board[x][y] != 0) { // 빈칸이 아닌 경우
		solve(n + 1);
	}
	else { // 빈칸인 경우
		for (int i = 1; i <= 9; i++) {
			if (row[x][i] == false && col[y][i] == false && square[getSquare(x, y)][i] == false) {
				// 숫자 i 놓기
				row[x][i] = col[y][i] = square[getSquare(x, y)][i] = true;
				board[x][y] = i;
				
				solve(n + 1);
				
				// 숫자 i 빼기
				row[x][i] = col[y][i] = square[getSquare(x, y)][i] = false;
				board[x][y] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 입력 받기
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			row[i][board[i][j]] = true;
			col[j][board[i][j]] = true;
			square[getSquare(i, j)][board[i][j]] = true;
		}
	}

	// 문제 풀기
	solve(0);

	// 종료
	return 0;
}
