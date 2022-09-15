#include <iostream>
#include <algorithm>

using namespace std;

int a[101];
long long d[101][21];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // input
    int n, goal;
    cin >> n;
    n--;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> goal;

    // dp
    d[0][a[0]] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j - a[i] >= 0) {
                d[i][j] += d[i - 1][j - a[i]];
            }
            if (j + a[i] <= 20) {
                d[i][j] += d[i - 1][j + a[i]];
            }
        }
    }

    // output
    cout << d[n - 1][goal] << '\n';

    return 0;
}
