#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool can(bool blind, char from, char to) { // 이동 가능한 정점인지 확인하는 함수
	if (from == to) return true;
	if (blind) {
		if (from == 'R' && to == 'G') return true;
		if (from == 'G' && to == 'R') return true;
	}
	return false;
}

int solve(vector<string> &a, bool blind = false) {
	// 초기화
	int n = a.size();
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	int ans = 0; // 구역 개수

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false) {
				// 구역 증가시키기
				ans += 1;
				// BFS
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				visited[i][j] = true;

				while (!q.empty()) {
					auto cur = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = cur.first + dx[i];
						int ny = cur.second + dy[i];

						if (nx >= 0 && nx < n && ny >= 0 && ny < n) { // 범위 체크
							if (visited[nx][ny] == false && can(blind, a[cur.first][cur.second], a[nx][ny])) { // 방문 여부, 색깔 체크
								q.push(make_pair(nx, ny));
								visited[nx][ny] = true;
							}
						}
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	// input
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// solve, output
	cout << solve(a) << ' ' << solve(a, true) << '\n';
	return 0;
}
