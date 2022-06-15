#include <iostream>
#include <algorithm>
#include <queue>
#define next _next // algorithm의 next함수와 변수명이 겹침
using namespace std;

int dist[101]; // dist[v]는 v에 도착하는 최소 주사위 횟수
int next[101]; // 주사위를 통해 도착한 칸이 x일 때 이동해야하는 칸

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력 및 초기화
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 100; i++) {
		next[i] = i;
		dist[i] = -1; // visited와 통합하여 사용. -1인 경우 방문 안 함, 다른 수인 경우 방문함
	}

	while (n--) {
		int x, y;
		cin >> x >> y;
		next[x] = y;
	}

	while (m--) {
		int x, y;
		cin >> x >> y;
		next[x] = y;
	}

	// 시작점 설정
	dist[1] = 0;
	queue<int> q;
	q.push(1);

	// BFS
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int y = x + i;
			if (y > 100) continue;
			y = next[y];
			if (dist[y] == -1) {
				dist[y] = dist[x] + 1;
				q.push(y);
			}
		}
	}

	// 출력 및 종료
	cout << dist[100] << '\n';
	return 0;

}
