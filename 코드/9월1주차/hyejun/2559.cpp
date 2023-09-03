#include <iostream>
#include <algorithm>
#include <climits>
#pragma warning(disable:4996)

using namespace std;

const int mx = 100004;
int n, k, a[mx], psum[mx], ans = INT_MIN;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    for (int i = k; i <= n; ++i) {
        ans = max(ans, psum[i] - psum[i - k]);
    }
    cout << ans << '\n';

    return 0;
}
