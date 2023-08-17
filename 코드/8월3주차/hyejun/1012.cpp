#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

const int mx = 54;
int a[mx][mx];
int visited[mx][mx];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int t, n, m, k, xx, yy, cnt;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (a[ny][nx] == 0) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    // 연결된 컴포넌트 개수 구하기 -> DFS, BFS
    // 문제에 주어진 맵으로 구현 시 O(N * M) -> O(50 * 50)
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> m >> n >> k;

        // 초기화
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        for (int i = 0; i < k; ++i) {
            cin >> xx >> yy;
            a[yy][xx] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 0) continue;
                if (visited[i][j]) continue;
                dfs(i, j);
                cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
