#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[102][102];
int visited[102][102];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int a, int b)
{
    visited[a][b] = 1;
    queue<pair<int, int>> q;
    q.push({a, b});

    int x, y;
    while (!q.empty())
    {
        tie(x, y) = q.front(); q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny]|| arr[nx][ny] == 0)
                continue;
            q.push({nx, ny});
            visited[nx][ny]=visited[x][y]+1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = s[j]-'0';
        }
    }

    bfs(0, 0);
    cout<<visited[n-1][m-1]<<'\n';

    return 0;
}
