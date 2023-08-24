#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 12;
int n, m, ans;
int a[mx][mx], visited[mx][mx];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
vector<pp> emp;
vector<pp> virus;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (visited[ny][nx] || a[ny][nx] != 0) continue;
        dfs(ny, nx);
    }
    return;
}

int solve() {
    memset(visited, 0, sizeof(visited));
    for (pp vir : virus) {
        dfs(vir.first, vir.second);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }
    return cnt;
}

void wall() {
    for (int i = 0; i < emp.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < j; ++k) {
                a[emp[i].first][emp[i].second] = 1;
                a[emp[j].first][emp[j].second] = 1;
                a[emp[k].first][emp[k].second] = 1;
                ans = max(ans, solve());
                // 원복
                a[emp[i].first][emp[i].second] = 0;
                a[emp[j].first][emp[j].second] = 0;
                a[emp[k].first][emp[k].second] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 0) emp.push_back(make_pair(i, j));
            if (a[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    wall();
    cout << ans << '\n';
    
    return 0;
}
