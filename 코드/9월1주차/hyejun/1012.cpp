#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

const int mx = 54;
int n, m, k, a[mx][mx], visited[mx][mx], cnt;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (!a[ny][nx] || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t, x, y;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(visited));
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; ++i) {
            cin >> x >> y;
            a[y][x] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j] || visited[i][j]) continue;
                cnt++;
                dfs(i, j);
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
