#include <iostream>
// #pragma warning(disable:4996)

using namespace std;
const int mx = 20;
int n, a[mx][mx], dp[mx][mx][3];

bool canGo(int y, int x, int dir) {
    if (dir == 0 || dir == 1) {
        if (!a[y][x]) return true;
    }
    else if (dir == 2) {
        if (a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) return true;
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout); 

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    dp[1][2][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // 현재 가로 방향
            if (canGo(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if (canGo(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][0];
            // 현재 세로 방향
            if (canGo(i + 1, j, 1)) dp[i + 1][j][1] += dp[i][j][1];
            if(canGo(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][1];
            // 현재 대각선 방향
            if (canGo(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][2];
            if (canGo(i + 1, j, 1)) dp[i + 1][j][1] += dp[i][j][2];
            if (canGo(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][2];
        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << '\n';

    return 0;
}
