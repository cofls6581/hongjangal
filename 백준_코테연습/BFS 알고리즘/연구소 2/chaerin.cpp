#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int a[51][51];
int d[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
vector<pair<int, int>> candi;
int ans = -1;

void bfs() { //bfs 로직
	memset(d, -1, sizeof(d));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 3) { //바이러스
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
				if (a[nx][ny] != 1 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 1) {
				if (d[i][j] == -1) return;
				if (cur < d[i][j]) cur = d[i][j];
			}
		}
	}
	if (ans == -1 || ans > cur) {
		ans = cur;
	}
}

void virus(int idx, int cnt) { // 바이러스 위치 지정
    if (idx == candi.size()) {
		if (cnt == m) {
			bfs();
		}
	}
	else {
		int x, y;
		tie(x, y) = candi[idx];
		a[x][y] = 3; // 바이러스 존재 o
		virus(idx + 1, cnt + 1);
		a[x][y] = 0; // 바이러스 존재 x
		virus(idx + 1, cnt);
	}
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) { //바이러스 놓을 수 있는 위치
				a[i][j] = 0;
				candi.push_back(make_pair(i, j));
			}
		}
	}
    //로직
    virus(0,0);
    //output
    cout << ans << '\n';
    return 0;
}
