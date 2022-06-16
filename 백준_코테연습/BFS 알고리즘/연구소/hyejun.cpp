#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[8][8];
int tmp[8][8];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans;

int bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = arr[i][j];
			if (arr[i][j] == 2) { // 바이러스가 있는 모든 칸이 시작점임
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) { // 바이러스 퍼뜨리면서 bfs 진행
		pair<int, int> x = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x.first + dx[i];
			int ny = x.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (tmp[nx][ny] == 0) {
				tmp[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int safe_cnt = 0;
	for (int i = 0; i < n; i++) { // 안전영역의 크기 구하기
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0)
				safe_cnt++;
		}
	}
	return safe_cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) {
			if (arr[x1][y1] != 0) continue;
			for (int x2 = 0; x2 < n; x2++) {
				for (int y2 = 0; y2 < m; y2++) {
					if (arr[x2][y2] != 0) continue;
					for (int x3 = 0; x3 < n; x3++) {
						for (int y3 = 0; y3 < m; y3++) {
							if (arr[x3][y3] != 0) continue;
							if (x1 == x2 && y1 == y2) continue;
							if (x2 == x3 && y2 == y3) continue;
							if (x3 == x1 && y3 == y1) continue;
							// 벽 3개 세우기
							arr[x1][y1] = 1;
							arr[x2][y2] = 1;
							arr[x3][y3] = 1;
							// 바이러스가 퍼진 곳 탐색
							int cur = bfs();
							if (ans < cur) ans = cur;
							// 벽 원상복구 시키기
							arr[x1][y1] = 0;
							arr[x2][y2] = 0;
							arr[x3][y3] = 0;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
