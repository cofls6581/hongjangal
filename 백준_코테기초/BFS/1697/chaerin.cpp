#include <iostream>
#include <queue>
# define MAX 100001

using namespace std;

int x, y;
int visit[MAX];

void bfs(int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, 0));
	visit[x] = 1;
	while (!q.empty()) {
		int loc = q.front().first;
		int count = q.front().second;
		q.pop();
		if (loc == y)
			cout << count << endl;
		if (loc + 1 < MAX && !visit[loc + 1]) {
			visit[loc + 1] = 1;
			q.push(make_pair(loc + 1, count + 1));
		}
		if (loc - 1 < MAX && !visit[loc - 1]) {
			visit[loc - 1] = 1;
			q.push(make_pair(loc - 1, count + 1));
		}
		if (loc * 2 < MAX && !visit[loc * 2]) {
			visit[loc * 2] = 1;
			q.push(make_pair(loc * 2, count + 1));
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> x >> y;
	bfs(x);
	return 0;
}