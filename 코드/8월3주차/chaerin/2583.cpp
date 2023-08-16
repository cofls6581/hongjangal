#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int arr[102][102];
int visited[102][102]={0,};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int temp=0;
vector <int> ansArr;

void dfs(int x, int y)
{
    visited[x][y] = 1;
    temp++;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visited[nx][ny] != 0 || nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        if (arr[nx][ny] == 1)
            dfs(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> m >> n >> k;

    fill(&arr[0][0],&arr[0][0]+102*102,1);
    int a, b, c, d;
    while(k--){
        cin >> a >> b >> c >> d;
        for (int j = b; j < d; ++j)
        {
            for (int h =a; h < c; ++h)
            {
                arr[j][h] = 0;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[i][j] == 1 && visited[i][j] == 0)
            {
                temp=0;
                dfs(i, j);
                ansArr.push_back(temp);
            }
        }
    }

    cout << ansArr.size() << '\n';
    sort(ansArr.begin(),ansArr.end());
    for(int a : ansArr){
        cout<<a<<' ';
    }
    cout<<'\n';

    return 0;
}
