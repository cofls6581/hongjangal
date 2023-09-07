#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pp;
const int mx = 1000004;
ll n, x, y, ans;
pp a[mx];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        a[i] = { x,y };
    }
    sort(a, a + n);
    ll l = a[0].first;
    ll r = a[0].second;
    for (int i = 1; i < n; ++i) {
        if (r < a[i].first) { // 완전 떨어져 있는 경우
            ans += (r - l);
            l = a[i].first;
            r = a[i].second;
        }
        else if (a[i].first <= r && a[i].second >= r) { // 앞에꺼랑 겹치는 경우
            r = a[i].second;
        }
    }
    ans += r - l;
    cout << ans << '\n';

    return 0;
}
