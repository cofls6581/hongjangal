#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int prime[10000];
bool visited[10000];
int dist[10000];

int change(int num, int pos, int digit) { // 한 자리 숫자 바꾸는 함수
	if (pos == 0 && digit == 0) return -1; // 네 자리 수가 아닌 경우 -1 리턴
	string s = to_string(num);
	s[pos] = digit + '0';
	return stoi(s);
}

void bfs(int n) { // BFS 함수
	queue<int> q;
	q.push(n);
	visited[n] = true;
	dist[n] = 0;
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 9; j++) {
				int next = change(cur, i, j);
				if (next != -1) { // 네 자리 수가 맞으면
					if (prime[next] != 0 && visited[next] == false) {
						q.push(next);
						visited[next] = true;
						dist[next] = dist[cur] + 1;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// 소수 구하기 (에라토스테네스의 체)
	for (int i = 2; i <= 9999; i++) {
		prime[i] = i;
	}
	for (int i = 2; i <= 9999; i++) {
		if (prime[i] == 0) continue;
		for (int j = i + i; j <= 9999; j += i) {
			prime[j] = 0;
		}
	}

	// input
	int t, n, m;
	cin >> t;

	// 테스트케이스마다 BFS
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		// 초기화
		memset(visited, false, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		// BFS
		bfs(n);
		// output
		if (visited[m] == true) {
			cout << dist[m] << '\n';
		}
		else {
			cout << "Impossible" << '\n';
		}
	}
	return 0;
}
