#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
#define MAX 300

using namespace std;

int N, M;
int arr[MAX][MAX];
int future[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;

	while (!q.empty()) {
		int cur_x, cur_y;
		tie(cur_x, cur_y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (visit[nx][ny] == false && arr[nx][ny] > 0) {
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int solve() {
	int year = 0;
	while (1) {
		// 초기화
		memset(visit, false, sizeof(visit));
		memset(future, 0, sizeof(future));
		int iceCnt = 0;

		// 탐색
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] > 0 && visit[i][j] == false) {
					// 빙산 덩어리 개수 증가
					iceCnt++;
					bfs(i, j);
				}
			}
		}

		// 개수가 2개가 되거나 다 녹으면 종료
		if (iceCnt >= 2) return year;
		if (iceCnt == 0) return 0;

		// 높이 감소 저장
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int seaCnt = 0;
				// 동서남북 체크
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (arr[nx][ny] == 0) seaCnt++;
				}
				future[i][j] = arr[i][j] - seaCnt;
				if (future[i][j] < 0) future[i][j] = 0;
			}
		}

		// 실제 높이 감소
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = future[i][j];
			}
		}

		// 년도 증가
		year++;

	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	
	// solve, output
	cout << solve() << '\n';
	
	return 0;
}
