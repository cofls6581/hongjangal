#include <iostream>
using namespace std;

int N, M;
char a[50][50];
bool check[50][50];
int dist[50][50];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool dfs(int x, int y, int cnt, char color) {
	if (check[x][y]) return cnt - dist[x][y] >= 4;
	check[x][y] = true;
	dist[x][y] = cnt;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= 0 ny && ny < M) {
			if (a[nx][ny] == color) {
				if (dfs(nx, ny, cnt + 1, color)) return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> a[i][j];
		}
	}
	bool cycleExists = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (dfs(i, j, 0, a[i][j])) {
				cycleExists = true;
				break;
			}
		}
		if (cycleExists == true) break;
	}
	if (cycleExists == true) {
		cout << "Yes" << '\n';
	}
	else {
		cout << "No" << '\n';
	}
	return 0;
}
