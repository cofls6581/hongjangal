#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 200

int n, a1, b1, a2, b2;
int visited[MAX][MAX];
int dx[] = { -2, -2, 0, 0, 2, 2 };
int dy[] = { -1, 1, -2, 2, -1, 1 };
queue <pair<int, int>> q;

int bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == a2 && y == b2) {
			return visited[x][y];
		}

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (visited[nx][ny] != -1 || nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push(make_pair(nx, ny));
		}

	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력 및 초기화
	cin >> n;
	cin >> a1 >> b1 >> a2 >> b2;

	memset(visited, -1, sizeof(visited));
	visited[a1][b1] = 0;
	q.push(make_pair(a1, b1));

	// 출력 및 종료
	cout << bfs();

	return 0;
}
