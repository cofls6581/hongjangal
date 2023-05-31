#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>

#define MAX 1000

using namespace std;

int box[MAX][MAX];
queue<pair<int, int>> redTomato;
int dist[MAX][MAX];
int M, N;
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int ans = 0;

void BFS() {
	while (!redTomato.empty()) {
		int x, y;
		tie(x, y) = redTomato.front();
		redTomato.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[nx][ny] == -1 && box[nx][ny] == 0) { // 방문하지 않았고 익지 않은 토마토
				dist[nx][ny] = dist[x][y] + 1;
				redTomato.push(make_pair(nx, ny));
			}
		}
	}
}

void findAnswer() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (box[i][j] == 0 && dist[i][j] == -1) {
				ans = -1;
				return;
			}
			if (dist[i][j] > ans) {
				ans = dist[i][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// init
	fill(&dist[0][0], &dist[MAX - 1][MAX], -1);
	// input
	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				redTomato.push(make_pair(i, j)); // bfs 돌릴 큐에 삽입
				dist[i][j] = 0;
			}
		}
	}
	// solve
	BFS();
	findAnswer();
	// output
	cout << ans << '\n';
}
