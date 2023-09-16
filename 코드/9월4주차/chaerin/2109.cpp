#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, d, p;
vector<pair<int, int>> v;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(v[i].second);
        if (pq.size() > v[i].first)
        {
            pq.pop();
        }
    }

    while (pq.size())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';

    return 0;
}
