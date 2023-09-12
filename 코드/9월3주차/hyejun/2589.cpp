#include <iostream>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 54;
int n, m, visited[mx][mx], ans = -1;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0, -1 };
string s;
char a[mx][mx];

int bfs(int sy, int sx) {
    int ret = -1;
    queue<pp> q;
    visited[sy][sx] = 1; // 마지막에 1 빼기
    q.push({ sy, sx });
    while (q.size()) {
        pp cur = q.front(); q.pop();
        int y = cur.first;
        int x = cur.second;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx] || a[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            ret = visited[ny][nx];
            q.push({ ny,nx });
        }
    }
    return ret;
}

void go() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'L') {
                fill(&visited[0][0], &visited[0][0] + mx * mx, 0);
                ans = max(ans, bfs(i, j) - 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j];
        }
    }
    go();
    cout << ans << '\n';

    return 0;
}
