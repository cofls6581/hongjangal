#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int visited[1000001];

void bfs() {
	queue<int> q;
	visited[S] = 1;
	q.push(S);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		if (now == G) return; // 목적지 도달

		int nextU = now + U;
		int nextD = now - D;

		if (nextU <= F && visited[nextU] == 0) { // 올라갈 수 있을 때
			visited[nextU] = visited[now] + 1;
			q.push(nextU);
		}
		if (nextD >0 && visited[nextD] == 0) { // 내려갈 수 있을 때
			visited[nextD] = visited[now] + 1;
			q.push(nextD);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;

	bfs();

	if (visited[G]) cout << visited[G] - 1 << '\n'; // visited[S] = 1로 시작했으므로 결과 - 1을 출력한다.
	else cout << "use the stairs\n";
	
	return 0;
}
