#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int a[50][50];
int area[50][50]; // 구역 번호 (방문 여부도 검사 가능)
int areaSize[50 * 50 + 1]; // 구역 넓이
int dx[4] = { 0,-1,0,1 }; // 서,북,동,남 방향
int dy[4] = { -1,0,1,0 };

int bfs(int i, int j, int areaNum) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	area[i][j] = areaNum;
	int cnt = 0; // 방문한 정점 개수 (구역 넓이 계산)
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt += 1;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 검사
			if (area[nx][ny] != 0) continue; // 방문 여부 검사
			if (a[x][y] & (1 << k)) continue; // 벽 검사
			q.push(make_pair(nx, ny));
			area[nx][ny] = areaNum;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// input
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	// 구역 개수
	int areaNum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (area[i][j] == 0) { // 방문하지 않았다면
				areaNum += 1;
				areaSize[areaNum] = bfs(i, j, areaNum);
			}
		}
	}
	cout << areaNum << '\n';
	// 가장 넓은 방의 넓이
	int maxSize = 0;
	for (int i = 1; i <= areaNum; i++) {
		if (maxSize < areaSize[i]) {
			maxSize = areaSize[i];
		}
	}
	cout << maxSize << '\n';
	// 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
	int newMaxSize = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = i;
			int y = j;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (area[nx][ny] == area[x][y]) continue; // 같은 구역이면 넘어가기
				if (a[x][y] & (1 << k)) {
					if (newMaxSize < areaSize[area[x][y]] + areaSize[area[nx][ny]]) {
						newMaxSize = areaSize[area[x][y]] + areaSize[area[nx][ny]];
					}
				}
			}
		}
	}
	cout << newMaxSize << '\n';
	return 0;
}
