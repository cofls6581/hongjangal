#include <iostream>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

const int mx = 104;
int a[mx][mx];
int visited[mx][mx];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int n, cnt, ans = -1;

void dfs(int y, int x, int rain) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (visited[ny][nx]) continue;
        if (a[ny][nx] <= rain) continue;
        dfs(ny, nx, rain);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    // 연결된 컴포넌트 개수 구하기 -> DFS, BFS
    // 문제에 주어진 맵으로 구현 시 O(N^2 * H) -> O(10^6)
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int rain = 0; rain <= 100; ++rain) {
        // 초기화
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) continue;
                if (a[i][j] <= rain) continue;
                dfs(i, j, rain);
                cnt++;
            }
        }

        ans = max(ans, cnt);
    }
    cout << ans << '\n';

    return 0;
}
