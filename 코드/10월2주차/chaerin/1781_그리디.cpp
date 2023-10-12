#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    int d, c;
    for (int i = 0; i < n; ++i)
    {
        cin >> d >> c;
        v.push_back({d, c});
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<v.size();++i){
        ans+=v[i].second;
        pq.push(v[i].second);
        if (pq.size() > v[i].first) {
            ans -= pq.top();
            pq.pop();
        }
    }

    cout << ans << '\n';

    return 0;
}
