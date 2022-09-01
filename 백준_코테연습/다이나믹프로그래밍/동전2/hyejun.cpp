#include <iostream>
#include <algorithm>

using namespace std;

int value[101];
int d[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // input
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    // dp
    for (int i = 1; i <= k; i++) {
        d[i] = 10001;
    }

    for (int i = 0; i < n; i++) {
        for (int j = value[i]; j <= k; j++) {
            d[j] = min(d[j], d[j - value[i]] + 1);
        }
    }

    // output
    if (d[k] != 10001) {
        cout << d[k] << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
