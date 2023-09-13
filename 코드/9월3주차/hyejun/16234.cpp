#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 54;
int n, l, r, a[mx][mx], ans = 0, flag, visited[mx][mx], psum;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
vector<pp> v;

int dfs(int y, int x) {
    int ret = 1;
    visited[y][x] = 1;
    psum += a[y][x];
    v.push_back({ y,x }); // 연합국 좌표 저장
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (visited[ny][nx]) continue;
        if ((l <= abs(a[y][x] - a[ny][nx])) && (r >= abs(a[y][x] - a[ny][nx]))) {
            ret += dfs(ny, nx);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    while (1) {
        flag = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) continue;
                v.clear();
                psum = 0;
                int ret = dfs(i, j);
                int val = psum / ret;
                if (v.size() == 1) continue;
                flag = 1;
                for (pp each : v) {
                    a[each.first][each.second] = val;
                }
            }
        }
        if (!flag) break;
        ans++;
    }
    cout << ans << '\n';

    return 0;
}
