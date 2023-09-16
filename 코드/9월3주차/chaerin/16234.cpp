#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;
#define MAX 52

int n, l, r;
int a[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int area;
int ans = 0;
bool isFind;
vector<pair<int, int>> v;

void dfs(int x, int y)
{
    visited[x][y] = 1;
    v.push_back({x, y});
    area+=a[x][y];

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (visited[nx][ny])
            continue;
        int diff=abs(a[x][y]-a[nx][ny]);
        if((l<=diff)&&(diff<=r)){
            isFind = true;
            dfs(nx,ny);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> r;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }

    while (true)
    {
        isFind = false;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j])
                {
                    area = 0;
                    v.clear();
                    dfs(i, j);
                    for (auto vv : v)
                    {
                        a[vv.first][vv.second] = (area / v.size());
                    }
                }
            }
        }
        if (!isFind) break;
        else ans++;
    }

    cout<<ans<<'\n';

    return 0;
}
