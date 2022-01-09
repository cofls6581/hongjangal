#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 301

int testN, n;
int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int cX, cY, dX, dY;
int visit[MAX][MAX];
int ans[MAX][MAX];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	visit[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == dX && y == dY)
			cout << ans[x][y] << '\n';
		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && 0 <= ny && nx < n && ny < n && !visit[nx][ny]) {
				visit[nx][ny] = 1;
				q.push({ nx,ny });
				ans[nx][ny] = ans[x][y] + 1;
			}

		}

	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> testN;
	for (int i = 0; i < testN; ++i) {
		cin >> n;
		cin >> cX >> cY >> dX >> dY;
		memset(visit, 0, sizeof(visit));
		memset(ans, 0, sizeof(ans));
		bfs(cX, cY);
	}

	return 0;
}