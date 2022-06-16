#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int a[10][10];
int b[10][10]; // bfs에서 사용
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans;

int bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = a[i][j];
			if (a[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> x = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x.first + dx[i];
			int ny = x.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (b[nx][ny] == 0) {
				b[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) {
			if (a[x1][y1] != 0) continue;
			for (int x2 = 0; x2 < n; x2++) {
				for (int y2 = 0; y2 < m; y2++) {
					if (a[x2][y2] != 0) continue;
					for (int x3 = 0; x3 < n; x3++) {
						for (int y3 = 0; y3 < m; y3++) {
							if (a[x3][y3] != 0) continue;
							if (x1 == x2 && y1 == y2) continue;
							if (x2 == x3 && y2 == y3) continue;
							if (x3 == x1 && y3 == y1) continue;
							// 벽 세우기
							a[x1][y1] = 1;
							a[x2][y2] = 1;
							a[x3][y3] = 1;
							// 파이러스가 퍼질수 없는 곳 구하기
							int cur = bfs();
							if (ans < cur) ans = cur;
							// 원래 상태로
							a[x1][y1] = 0;
							a[x2][y2] = 0;
							a[x3][y3] = 0;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
