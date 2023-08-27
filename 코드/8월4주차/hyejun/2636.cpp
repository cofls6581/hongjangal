#include <iostream>
#include <cstring>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 104;
int n, m, a[mx][mx], visited[mx][mx], cnt1, cnt2;
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
vector<pp> v;

void go(int y, int x) {
    visited[y][x] = 1;
    if (a[y][x] == 1) {
        v.push_back({ y,x });
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (visited[ny][nx]) continue;
        go(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    while (1) {
        memset(visited, 0, sizeof(visited));
        cnt2 = 0;
        v.clear();
        go(0, 0);
        for (pp i : v) {
            a[i.first][i.second] = 0;
            cnt2++;
        }
        cnt1++;
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0) flag = 1;
            }
        }
        if (!flag) break;
    }
    cout << cnt1 << '\n' << cnt2 << '\n';

    return 0;
}
