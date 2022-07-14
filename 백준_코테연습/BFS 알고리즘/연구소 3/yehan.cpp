#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int board[100][100];
int d[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
vector<pair<int, int>> candi;
int ans = -1;

void bfs() {
	memset(d, -1, sizeof(d));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 3) {
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (board[nx][ny] != 1 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				if (d[i][j] == -1) return;
				if (cur < d[i][j]) cur = d[i][j];
			}
		}
	}
	if (ans == -1 || ans > cur) {
		ans = cur;
	}
}

void spot(int idx, int cnt) { // 바이러스를 놓을 자리를 결정하는 함수
	if (idx == candi.size()) {
		if (cnt == m) {
			bfs();
		}
	}
	else {
		int x, y;
		tie(x, y) = candi[idx];
		board[x][y] = 3; // 바이러스를 활성 상태로 바꾼다.
		spot(idx + 1, cnt + 1);
		board[x][y] = 2; // 비활성 상태를 유지한다.
		spot(idx + 1, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력 및 초기화
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				// board[i][j] = 0;
				candi.push_back(make_pair(i, j));
			}
		}
	}

	// 문제 풀기
	spot(0, 0);

	// 출력 및 종료
	cout << ans << '\n';
	return 0;
}
