#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
using namespace std;

int input[1000][1000];
int d[1000][1000][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	// 변수 선언 및 초기화
	int n, m;
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &input[i][j]);
		}
	}

	// bfs
	queue < tuple<int, int, int>> q;
	d[0][0][0] = 1;
	q.push(make_tuple(0, 0, 0));
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny<0 || ny>=m) continue;
			if (input[nx][ny] == 0 && d[nx][ny][z] == 0) { // 빈칸으로 이동한 경우
				d[nx][ny][z] = d[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z));
			}
			if (z == 0 && input[nx][ny] == 1 && d[nx][ny][z + 1] == 0) { // 벽을 부숴 이동한 경우
				d[nx][ny][z + 1] = d[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z + 1));
			}
		}
	}

	// 출력 및 종료
	if (d[n - 1][m - 1][0] != 0 && d[n - 1][m - 1][1] != 0) {
		cout << min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]);
	}
	else if (d[n - 1][m - 1][0] != 0) cout << d[n - 1][m - 1][0];
	else if (d[n - 1][m - 1][1] != 0) cout << d[n - 1][m - 1][1];
	else cout << -1;

	return 0;
}
