#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pp;
int n, ans;
vector<pp> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int d, r;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> d >> r;
        v.push_back(make_pair(d, r));
    }
    sort(v.begin(), v.end()); // 데드라인순 정렬
    for (int i = 0; i < v.size(); ++i) {
        ans += v[i].second;
        pq.push(v[i].second);
        if (pq.size() > v[i].first) {
            ans -= pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';

    return 0;
}
