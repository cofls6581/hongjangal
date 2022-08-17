#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int d[101][100001];
int w[101];
int v[101];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // input
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    // dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            d[i][j] = d[i - 1][j]; // i번째 물건을 넣지 않는 경우

            if (j - w[i] >= 0) { // i번째 물건을 넣는 경우
                d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    // output
    cout << d[n][k] << '\n';

    return 0;
}
