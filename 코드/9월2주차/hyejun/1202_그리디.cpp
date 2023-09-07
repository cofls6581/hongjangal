#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pp;
ll n, k, m, v, c, ans;
vector<ll> bag;
vector<pp> jew;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> m >> v;
        jew.push_back({ m,v });
    }
    for (int i = 0; i < k; ++i) {
        cin >> c;
        bag.push_back(c);
    }
    sort(jew.begin(), jew.end());
    sort(bag.begin(), bag.end());
    priority_queue<ll> pq;
    int j_idx = 0;
    for (int i = 0; i < k; ++i) {
        while ((j_idx < n) && (bag[i] >= jew[j_idx].first)) pq.push(jew[j_idx++].second);
        if (pq.size()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';

    return 0;
}
