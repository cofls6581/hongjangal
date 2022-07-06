#include <iostream>
#include <queue>

using namespace std;

bool visited[1000001];
int dist[1000001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// input
	int floor, start, goal, up, down;
	cin >> floor >> start >> goal >> up >> down;
	// BFS
	queue<int> q;
	q.push(start);
	visited[start] = true;
	dist[start] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int next1 = cur + up;
		int next2 = cur - down;
		if (next1 >= 1 && next1 <= floor && visited[next1] == false) {
			q.push(next1);
			visited[next1] = true;
			dist[next1] = dist[cur] + 1;
		}
		if (next2 >= 1 && next2 <= floor && visited[next2] == false) {
			q.push(next2);
			visited[next2] = true;
			dist[next2] = dist[cur] + 1;
		}
	}
	// output
	if (visited[goal]) {
		cout << dist[goal] << '\n';
	}
	else {
		cout << "use the stairs" << '\n';
	}
	return 0;
}
