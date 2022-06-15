#include <iostream>
#include <queue>

using namespace std;

int arr[101];
int dist[101];

void bfs() {
	dist[1] = 0; // 1번째 칸에 도착하는 최소 주사위 던짐 횟수는 0
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			int y = x + i;
			if (y > 100) continue;
			y = arr[y];
			if (dist[y] == -1) {
				dist[y] = dist[x] + 1;
				q.push(y);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 100; i++) {
		arr[i] = i;
		dist[i] = -1;
	}
	int a, b;
	for (int i = 0; i < n; i++) { // 사다리
		cin >> a >> b;
		arr[a] = b;
	}
	for (int i = 0; i < m; i++) { // 뱀
		cin >> a >> b;
		arr[a] = b;
	}
	bfs();
	cout << dist[100] << '\n';
	return 0;
}
