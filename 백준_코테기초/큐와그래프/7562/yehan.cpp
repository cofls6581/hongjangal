#include <iostream>
#include <queue>
using namespace std;

#define MAX 301

int L;
int start_x, start_y, dst_x, dst_y;
int visited[MAX][MAX] = { 0 };
int path[MAX][MAX] = { 0 };
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };
queue<pair<int, int>> q;

void BFS(int cur_x, int cur_y) {
	visited[cur_x][cur_y] = 1;
	q.push(make_pair(cur_x, cur_y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == dst_x && y == dst_y) break;

		for (int i = 0; i < 8; ++i) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x < 0 || next_x >= L || next_y < 0 || next_y >= L)
				continue;

			if (visited[next_x][next_y] == 0) {
				visited[next_x][next_y] = 1;
				q.push(make_pair(next_x, next_y));
				path[next_x][next_y] = path[x][y] + 1;
			}
		}
	}
}

void initialize() {
	// BFS에 사용된 배열과 큐 초기화
	for(int i=0;i<L;++i)
		for (int j = 0; j < L; ++j) {
			visited[i][j] = 0;
			path[i][j] = 0;
		}
	while (!q.empty())
		q.pop();
}

int main() {
	int num_of_testcase;
	cin >> num_of_testcase;

	while (num_of_testcase--) {
		cin >> L;
		cin >> start_x >> start_y >> dst_x >> dst_y;

		BFS(start_x, start_y);

		cout << path[dst_x][dst_y] << '\n';

		initialize();
	}
	return 0;
}
