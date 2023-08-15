#include <bits/stdc++.h>
using namespace std;

int n, maxH = 0;
int ans = 0;
int arr[102][102] = {
    0,
};
int visited[102][102] = {
    0,
};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int h)
{
    visited[x][y] = 1;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visited[nx][ny] != 0 || nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (arr[nx][ny] > h)
            dfs(nx, ny, h);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
            maxH = max(maxH, arr[i][j]);
        }
    }
    
    for (int l = 0; l <= maxH; ++l)
    {
        memset(visited,0,sizeof(visited));
        int maxT = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (visited[i][j] == 0 && arr[i][j] > l)
                {
                    dfs(i, j, l);
                    maxT++;
                }
            }
        }
        ans = max(maxT, ans);
    }
    cout << ans << '\n';
    return 0;
}
