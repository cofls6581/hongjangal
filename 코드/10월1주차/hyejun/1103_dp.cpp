#include <iostream>
#include <algorithm>

using namespace std;

const int mx = 54, dir_mx = 4;
char a[mx][mx];
int n, m, dp[mx][mx], check[mx][mx];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int go(int y, int x) {
    // 기저사례
    if (y < 0 || y >= n || x < 0 || x >= m) return 0;
    if (a[y][x] == 'H') return 0;

    // 무한대 체크
    if (check[y][x]) {
        cout << -1 << '\n';
        exit(0);
    }

    // 메모이제이션
    int& ret = dp[y][x];
    if (ret) return ret;

    // 로직
    check[y][x] = 1;
    int val = (int)a[y][x] - '0';
    for (int i = 0; i < dir_mx; ++i) {
        int ny = y + dy[i] * val;
        int nx = x + dx[i] * val;
        ret = max(go(ny, nx) + 1, ret);
    }
    check[y][x] = 0;
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j)
            a[i][j] = s[j];
    }
    cout << go(0, 0) << '\n';

    return 0;
}
