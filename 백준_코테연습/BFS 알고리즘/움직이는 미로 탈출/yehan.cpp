#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int map[8][8][9];
int dx[9] = { 0, 0, 1, -1, 1, -1, 1, -1, 0 };
int dy[9] = { 1, -1, 0, 0, 1, 1, -1, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 변수 선언 및 초기화
	int n = 8;
	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	bool ans = false;

	// 문제 풀이 : BFS
	queue<tuple<int, int, int>> q;
	map[7][0][0] = true; 
	q.push(make_tuple(7, 0, 0));

	while (!q.empty()) {
		int x, y, t;
		tie(x, y, t) = q.front();
		q.pop();

		if (x == 0 && y == 7) {
			ans = true;
			break;
		}

		for (int k = 0; k < 9; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nt = min(t + 1, 8);
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (nx - t >= 0 && a[nx - t][ny] == '#') continue;
				if (nx - t - 1 >= 0 && a[nx - t - 1][ny] == '#') continue;
				if (map[nx][ny][nt] == false) {
					map[nx][ny][nt] == true;
					q.push(make_tuple(nx, ny, nt));
				}
			}
		}
	}

	// 출력 및 종료
	cout << (ans ? 1 : 0) << '\n';
	return 0;
}
