/*
DFS를 이용하여 풀이하였다.
연속된 칸을 가지는 테트로미노는 0,1,2,3 이렇게 순차적으로 숫자를 부여할 수 있다.
반면, ㅜ모양의 테트로미노는 그렇지 않아 따로 풀이하였다.
*/

#include <iostream>
using namespace std;

int board[500][500];
bool visit[500][500];
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 0;

void solve(int x, int y, int sum, int cnt) {
	if (cnt == 4) {
		if (ans < sum) ans = sum;
		return;
	}
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (visit[x][y]) return;

	visit[x][y] = true;
	for (int k = 0; k < 4; ++k) solve(x + dx[k], y + dy[k], sum + board[x][y], cnt + 1);
	visit[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// 모두 연속된 칸 풀이
			solve(i, j, 0, 0);

			// 마지막 테트로미노(ㅏ) - 깊이가 3이 나오지 않는 경우
			if (j + 2 < m) {
				int tmp = board[i][j] + board[i][j + 1] + board[i][j + 2];
				if (i - 1 >= 0) {
					int tmp2 = tmp + board[i - 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
				if (i + 1 < n) {
					int tmp2 = tmp + board[i + 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
			}
			if (i + 2 < n) {
				int tmp = board[i][j] + board[i + 1][j] + board[i + 2][j];
				if (j + 1 < m) {
					int tmp2 = tmp + board[i + 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
				if (j - 1 >= 0) {
					int tmp2 = tmp + board[i + 1][j - 1];
					if (ans < tmp2) ans = tmp2;
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
