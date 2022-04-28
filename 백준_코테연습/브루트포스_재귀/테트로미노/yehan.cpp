#include <iostream>
using namespace std;

int a[500][500];
bool c[500][500]; // 방문여부 검사
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 0;

void go(int x, int y, int sum, int cnt) {
	if (cnt == 4) { // 정답을 찾은 경우
		if (ans < sum) ans = sum;
		return;
	}
	if (x < 0 || x >= n || y < 0 || y >= m) return; // 범위를 벗어난 경우
	if (c[x][y]) return; // 이미 방문한 칸을 재방문 한 경우

	c[x][y] = true;
	for (int k = 0; k < 4; ++k) go(x + dx[k], y + dy[k], sum + a[x][y], cnt + 1);
	c[x][y] = false; // DFS와의 차이가 드러나는 부분!!
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// 모두 연속된 칸을 가지는 테트로미노에 대한 문제 풀이
			go(i, j, 0, 0);

			// 마지막 테트로미노 모양에 대한 예외 처리
			if (j + 2 < m) {
				int tmp = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i - 1 >= 0) {
					int tmp2 = tmp + a[i - 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
				if (i + 1 < n) {
					int tmp2 = tmp + a[i + 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
			}
			if (i + 2 < n) {
				int tmp = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j + 1 < m) {
					int tmp2 = tmp + a[i + 1][j + 1];
					if (ans < tmp2) ans = tmp2;
				}
				if (j - 1 >= 0) {
					int tmp2 = tmp + a[i + 1][j - 1];
					if (ans < tmp2) ans = tmp2;
				}
			}
		}
	}
	
	cout << ans << '\n';
	return 0;
}
