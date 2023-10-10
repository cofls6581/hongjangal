#include <bits/stdc++.h>
#define MAX 18
using namespace std;

int n;
int arr[MAX][MAX];
int dp[MAX][MAX][3];

bool check(int x, int y, int dir)
{
    if (x >= n || y >= n)
        return false;
    if (dir == 0 || dir == 1)
    { // 가로, 세로
        if (!arr[x][y])
            return true;
    }
    else if (dir == 2)
    { // 대각선
        if (arr[x][y] == 0 && arr[x - 1][y] == 0 && arr[x][y - 1] == 0)
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }
    dp[0][1][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // 가로
            if (check(i, j + 1, 0))
                dp[i][j + 1][0] += dp[i][j][0]; // 가로
            if (check(i + 1, j + 1, 2))
                dp[i + 1][j + 1][2] += dp[i][j][0]; // 대각선
            // 세로
            if (check(i + 1, j, 1))
                dp[i + 1][j][1] += dp[i][j][1]; // 세로
            if (check(i + 1, j + 1, 2))
                dp[i + 1][j + 1][2] += dp[i][j][1]; // 대각선
            // 대각선
            if (check(i + 1, j + 1, 2))
                dp[i + 1][j + 1][2] += dp[i][j][2]; // 대각선
            if (check(i, j + 1, 0))
                dp[i][j + 1][0] += dp[i][j][2]; // 가로
            if (check(i + 1, j, 1))
                dp[i + 1][j][1] += dp[i][j][2]; // 세로
        }
    }
    int ans = 0;
    ans = ans + dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
    cout << ans << '\n';
    return 0;
}
