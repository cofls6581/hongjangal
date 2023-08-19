#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

const int mx = 104;
int m, n, k;
int a[mx][mx];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int visited[mx][mx];
int cnt, node;
vector<int> sz;

void dfs(int y, int x) {
    visited[y][x] = true;
    node++; // 영역 넓이 증가
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (a[ny][nx] == -1) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> m >> n >> k;
    int x1, y1, x2, y2;
    for (int idx = 0; idx < k; ++idx) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = m - y2; i < m - y1; ++i) {
            for (int j = x1; j < x2; ++j) {
                a[i][j] = -1; // 직사각형 표시
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == -1) continue;
            if (visited[i][j]) continue;
            cnt++;
            node = 0;
            dfs(i, j);
            sz.push_back(node);
        }
    }

    sort(sz.begin(), sz.end());
    cout << cnt << '\n';
    for (int i = 0; i < sz.size(); ++i) {
        cout << sz[i] << ' ';
    }

    return 0;
}
