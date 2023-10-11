#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int mx = 24, asc_mx = 200;
int r, c, check[asc_mx], visited[mx][mx], ans = -1;
string s;
char a[mx][mx];
vector<char> v;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void go(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (visited[ny][nx] || check[(int)a[ny][nx]]) continue;
		visited[ny][nx] = 1;
		check[(int)a[ny][nx]] = 1;
		v.push_back(a[ny][nx]);

		go(ny, nx);

		visited[ny][nx] = 0;
		check[(int)a[ny][nx]] = 0;
		v.pop_back();
	}
	ans = max(ans, (int)v.size());
	return;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		cin >> s;
		for (int j = 0; j < c; ++j) {
			a[i][j] = s[j];
		}
	}
	visited[0][0] = 1;
	check[(int)a[0][0]] = 1;
	v.push_back(a[0][0]);
	go(0, 0);
	cout << ans << '\n';

    return 0;
}
