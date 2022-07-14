#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>

using namespace std;

int n, m;
int a[50][50];
int dist[50][50];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
vector<pair<int, int>> candi;
int ans = -1;

void bfs() {
	// BFS
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 3) {
				q.push(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) { // 범위 체크
				if (a[nx][ny] != 1 && dist[nx][ny] == -1) { // 벽, 방문 여부 체크
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	// 최소 시간 구하기
	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) { // 빈칸에 퍼뜨리는 최소시간을 구해야 함 (비활성화를 활성화시킨건 포함 X)
				if (dist[i][j] == -1) return; // 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우
				if (cur < dist[i][j]) cur = dist[i][j];
			}
		}
	}
	if (ans == -1 || ans > cur) {
		ans = cur;
	}
}

void putVirus(int index, int cnt) {
	if (index == candi.size()) {
		if (cnt == m) {
			bfs(); // 다 놓았으면 BFS
		}
	}
	else {
		int x, y;
		tie(x, y) = candi[index];
		a[x][y] = 3;
		putVirus(index + 1, cnt + 1);
		a[x][y] = 2; // 비활성 바이러스로 원상복구
		putVirus(index + 1, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				candi.push_back(make_pair(i, j));
			}
		}
	}
	// 바이러스 놓을 칸 고르기
	putVirus(0, 0);
	cout << ans << '\n';
	return 0;
}
