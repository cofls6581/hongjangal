#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

const int mx = 1000004;
int n, a[mx], x, cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> x;
    sort(a, a + n);
    int l = 0;
    int r = n - 1;
    int sm = 0;
    while (l < r) {
        sm = a[l] + a[r];
        if (sm == x) {
            cnt++;
            l++;
            r--;
        }
        else if (sm < x) l++;
        else r--;
    }
    cout << cnt << '\n';

    return 0;
}
