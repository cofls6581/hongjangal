#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int r1, c1, r2, c2;
bool visited[200][200];
int dist[200][200];
int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(r1, c1));
	visited[r1][c1] = true;

	while (!q.empty()) {
		pair<int, int> x = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x.first + dx[i];
			int ny = x.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (!visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				dist[nx][ny] = dist[x.first][x.second] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;
	bfs();
	if (dist[r2][c2] == 0) dist[r2][c2] = -1;
	cout << dist[r2][c2] << '\n';
	return 0;
}
