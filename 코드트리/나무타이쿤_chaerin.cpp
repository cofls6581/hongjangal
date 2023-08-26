#include <bits/stdc++.h>
using namespace std;

#define MAX 17

int tree[MAX][MAX];
int n, m, d, p;
bool nutrient[MAX][MAX] = {0,};
queue<pair<int, int>> q;

int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int diagx[] = {-1, -1, 1, 1};
int diagy[] = {1, -1, -1, 1};

pair<int, int> NextPos(int x, int y, int d, int p)
{
    int nx = (x + dx[d] * p + n * p) % n;
    int ny = (y + dy[d] * p + n * p) % n;

    return make_pair(nx, ny);
}

void moveNutrientAndGrow(int d, int p)
{
    int x, y;
    bool next_fert[MAX][MAX] = {0,};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (nutrient[i][j])
            {
                int nx, ny;
                tie(nx, ny) = NextPos(i, j, d, p);
                next_fert[nx][ny] = true;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            nutrient[i][j] = next_fert[i][j];
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (nutrient[i][j])
                tree[i][j]++;
}

void diagNutrient()
{

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (nutrient[i][j])
            {
                int cnt = 0;
                for (int k = 0; k < 4; ++k)
                {
                    int nx = i + diagx[k];
                    int ny = j + diagy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (tree[nx][ny] >= 1)
                        cnt++;
                }
                tree[i][j] += cnt;
            }
}

void cutTwo()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (nutrient[i][j])
                nutrient[i][j] = 0;
            else if (tree[i][j] >= 2)
            {
                nutrient[i][j] = 1;
                tree[i][j] -= 2;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> tree[i][j];
        }
    }

    for (int i = n - 2; i < n; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            nutrient[i][j] = 1;
            q.push({i, j});
        }
    }

    while (m--)
    {
        cin >> d >> p;
        moveNutrientAndGrow(d - 1, p);
        diagNutrient();
        cutTwo();
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ans += tree[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}
