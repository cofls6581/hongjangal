#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> gun[22][22];
int isPlayer[22][22][2];
int scores[32];

struct player
{
    int x, y;
    int d; // 방향
    int s; // 초기 능력치
    int g; // 총 공격력
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m >> k;

    int tmp;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> tmp;
            if (tmp != 0)
            {
                gun[i][j].push_back(tmp);
            }
        }
    }

    vector<player> p(m + 1);
    int x, y, d, s;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y >> d >> s;
        x -= 1;
        y -= 1;
        p[i].x = x;
        p[i].y = y;
        p[i].d = d;
        p[i].s = s;
        p[i].g = 0;
        isPlayer[x][y][0] = i;
    }

    while (k--)
    {
        for (int i = 1; i <= m; ++i)
        {
            // 이동
            int curx = p[i].x;
            int cury = p[i].y;
            int nx = curx + dx[p[i].d];
            int ny = cury + dy[p[i].d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            {
                int d = p[i].d;
                d = (d + 2) % 4;
                nx = curx + dx[d];
                ny = cury + dy[d];
                p[i].d = d;
            }
            p[i].x = nx;
            p[i].y = ny;
            isPlayer[curx][cury][0] = 0;
            // 플레이어 확인 후 결투 승패 결정
            int win, lose, score;
            if (isPlayer[nx][ny][0] != 0) // 플레이어 존재 o
            {
                int n1, attack1;
                int n2, attack2;
                n1 = i;
                attack1 = p[n1].s + p[n1].g;
                n2 = isPlayer[nx][ny][0];
                attack2 = p[n2].s + p[n2].g;
                score = abs(attack1 - attack2);
                if (attack1 > attack2)
                {
                    win = n1;
                    lose = n2;
                }
                else if (attack1 < attack2)
                {
                    win = n2;
                    lose = n1;
                }
                else
                {
                    if (p[n1].s > p[n2].s)
                    {
                        win = n1;
                        lose = n2;
                    }
                    else
                    {
                        win = n2;
                        lose = n1;
                    }
                }

                // 승패 로직 진행
                isPlayer[nx][ny][0] = win;
                scores[win] += score;

                gun[nx][ny].push_back(p[lose].g);
                p[lose].g = 0;
                for (int i = 0; i < 4; i++)
                {
                    int ndir = (p[lose].d + i) % 4;
                    int nnx = p[lose].x + dx[ndir], nny = p[lose].y + dy[ndir];
                    if (nnx < 0 || nnx >= n || nny < 0 || nny >= n)
                        continue;
                    if (isPlayer[nnx][nny][0] == 0)
                    {
                        p[lose].x = nnx;
                        p[lose].y = nny;
                        isPlayer[nnx][nny][0] = lose;
                        p[lose].d = ndir;
                        // lose 총 교체
                        gun[nnx][nny].push_back(p[lose].g);
                        sort(gun[nnx][nny].begin(), gun[nnx][nny].end(), greater<int>());
                        p[lose].g = gun[nnx][nny][0];
                        gun[nnx][nny].erase(gun[nnx][nny].begin());
                        break;
                    }
                }
                // win 총 교체
                gun[nx][ny].push_back(p[win].g);
                sort(gun[nx][ny].begin(), gun[nx][ny].end(), greater<int>());
                p[win].g = gun[nx][ny][0];
                gun[nx][ny].erase(gun[nx][ny].begin());
            }
            else
            { // 플레이어 존재 x
                gun[nx][ny].push_back(p[i].g);
                sort(gun[nx][ny].begin(), gun[nx][ny].end(), greater<int>());
                p[i].g = gun[nx][ny][0];
                gun[nx][ny].erase(gun[nx][ny].begin());
                isPlayer[nx][ny][0] = i;
            }
        }
    }
    // ans
    for (int i = 1; i <= m; i++)
        cout << scores[i] << " ";
    cout << '\n';
    return 0;
}
