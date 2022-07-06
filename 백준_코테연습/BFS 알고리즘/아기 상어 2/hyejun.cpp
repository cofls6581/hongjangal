#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

// bool visited[50][50];
// int dist[50][50];
int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dy[8] = { 1,-1,1,-1,0,1,-1,0 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// input
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	// BFS
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) continue;
			vector<vector<bool>> visited(n, vector<bool>(m, false));
			vector<vector<int>> dist(n, vector<int>(m, 0));
			// 안전거리 계산
			if (!visited[i][j]) {
				// BFS
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				visited[i][j] = true;
				dist[i][j] = 0;
				while (!q.empty()) {
					int x, y;
					tie(x, y) = q.front();
					q.pop();
					if (a[x][y] == 1) { // 아기 상어
						if (dist[x][y] > ans) ans = dist[x][y];
						break;
					}
					for (int i = 0; i < 8; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
							if (!visited[nx][ny]) {
								q.push(make_pair(nx, ny));
								visited[nx][ny] = true;
								dist[nx][ny] = dist[x][y] + 1;
							}
						}
					}
				}
			}
		}
	}
	// output
	cout << ans << '\n';
	return 0;
}
