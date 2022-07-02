#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool can(bool blind, char from, char to) {
	if (from == to) return true;
	if (blind) {
		if (from == 'R' && to == 'G') return true;
		if (from == 'G' && to == 'R') return true;
	}
	return false;
}

int dfs(vector<string>& a, bool blind = false) {
	int n = a.size();
	vector<vector<bool>> check(n, vector<bool>(n, false));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false) {
				ans += 1;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				check[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
							if (check[nx][ny]) continue;
							if (can(blind, a[x][y], a[nx][ny])) {
								q.push(make_pair(nx, ny));
								check[nx][ny] = true;
							}
						}
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << dfs(a) << ' ' << dfs(a, true) << '\n';
	return 0;
}
