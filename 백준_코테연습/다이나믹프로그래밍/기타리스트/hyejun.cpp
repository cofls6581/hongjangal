#include <iostream>
#include <algorithm>

using namespace std;

int n, s, m;
int v[51];
int d[51][1001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // input
    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // dp
    d[0][s] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (d[i - 1][j] == 1) {
                if (j + v[i] <= m) d[i][j + v[i]] = 1; // 볼륨이 m 이하인지 체크
                if (j - v[i] >= 0) d[i][j - v[i]] = 1; // 볼륨이 0 이상인지 체크
            }
        }
    }

    // output
    for (int i = m; i >= 0; i--) {
        if (d[n][i] == 1) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}
