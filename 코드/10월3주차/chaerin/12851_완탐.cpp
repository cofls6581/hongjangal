#include <bits/stdc++.h>
using namespace std;

int n, k;
bool visited[100002];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void bfs()
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = 1;
    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        visited[cur] = 1;
        if (cur == k) //참고: bfs라 우선순위큐 사용할 필요없으나 이전 로직에 사용하던 코드 재사용
        {
            if (pq.empty())
            {
                pq.push({cnt, 1});
            }
            else
            {
                int tmp = pq.top().first;
                if (tmp == cnt)
                {
                    int tmp2 = pq.top().second;
                    pq.pop();
                    pq.push({cnt, tmp2 + 1});
                }
                else
                    pq.push({cnt, 1});
            }
        }

        if (cur * 2 <= 100000 && !visited[cur * 2])
            q.push({cur * 2, cnt + 1});
        if (cur + 1 <= 100000 && !visited[cur + 1])
            q.push({cur + 1, cnt + 1});
        if (cur - 1 >= 0 && !visited[cur - 1])
            q.push({cur - 1, cnt + 1});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;
    bfs();
    cout << pq.top().first << '\n'
         << pq.top().second << '\n';

    return 0;
}
