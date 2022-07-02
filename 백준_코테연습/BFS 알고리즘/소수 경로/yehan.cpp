#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

bool prime[10001];
bool visited[10001];
int dist[10001];

int change(int num, int idx, int digit) {
	if (idx == 0 && digit == 0) return -1;
	string s = to_string(num);
	s[idx] = digit + '0';
	return stoi(s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 에라토스테네스의 체
	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == false) {
			for (int j = i * i; j <= 10000; j += i) {
				prime[j] = true;
			}
		}
	}
	for (int i = 0; i <= 10000; i++) {
		prime[i] = !prime[i];
	}

	int t;
	cin >> t;
	while (t--) {
		// 변수
		int n, m;
		cin >> n >> m;
		memset(visited, false, sizeof(visited));
		memset(dist, 0, sizeof(dist));

		// BFS
		dist[n] = 0;
		visited[n] = true;
		queue<int> q;
		q.push(n);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int next = change(cur, i, j);
					if (next != -1) {
						if (prime[next] && visited[next] == false) {
							q.push(next);
							dist[next] = dist[cur] + 1;
							visited[next] = true;
						}
					}
				}
			}
		}
		cout << dist[m] << '\n';
	}
	return 0;
}
