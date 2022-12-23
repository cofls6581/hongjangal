/*
교환을 딱 한번만 할 수 있는 케이스
최대 2500번(50*50) 교환 => 부르트포스로 해결
가로로 교환하는 경우와 세로로 교환하는 경우로 나누어서 풀이
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
char board[50][50];

void countMax() {
	int cnt;

	// 행 단위로 확인하기
	for (int i = 0; i < n; i++) {
		cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (board[i][j] == board[i][j + 1]) {
				cnt++;
				ans = max(cnt, ans);
			}
			else cnt = 1;
		}
	}

	// 열 단위로 확인하기
	for (int i = 0; i < n; i++) {
		cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (board[j][i] == board[j + 1][i]) {
				cnt++;
				ans = max(cnt, ans);
			}
			else cnt = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	// 좌우로 교환하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(board[i][j], board[i][j + 1]);
			countMax();
			swap(board[i][j], board[i][j + 1]);

		}
	}

	// 상하로 교환하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(board[j][i], board[j + 1][i]);
			countMax();
			swap(board[j][i], board[j + 1][i]);

		}
	}

	cout << ans << '\n';
	return 0;
}
