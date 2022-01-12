#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

int visited[MAX] = { 0 };
int path[MAX]= { 0 };
queue<int> q;

void BFS(int pos, int dst) {
	q.push(pos);
	visited[pos] = 1;

	while (!q.empty()) {
		int cur_pos = q.front();
		q.pop();

		// 1. X - 1의 위치로 이동하는 경우
		if ((cur_pos - 1 >= 0) && (visited[cur_pos - 1] == 0)) {
			q.push(cur_pos - 1);
			visited[cur_pos - 1] = 1;
			path[cur_pos - 1] = path[cur_pos] + 1;
		}
		// 2. X + 1의 위치로 이동하는 경우
		if ((cur_pos + 1 < MAX) && (visited[cur_pos + 1] == 0)) {
			q.push(cur_pos + 1);
			visited[cur_pos + 1] = 1;
			path[cur_pos + 1] = path[cur_pos] + 1;
		}
		// 3. 2 * X의 위치로 이동하는 경우
		if ((cur_pos * 2 < MAX) && (visited[cur_pos * 2] == 0)) {
			q.push(cur_pos * 2);
			visited[cur_pos * 2] = 1;
			path[cur_pos * 2] = path[cur_pos] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int start, dst;
	cin >> start >> dst;

	BFS(start, dst);
	
	cout << path[dst] << '\n';
	return 0;
}
