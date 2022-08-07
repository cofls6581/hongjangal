#include <iostream>
#include <vector>

using namespace std;

void dp(int n, vector<int> &a, vector<vector<int>> &d) {
    for (int i = 0; i < n; i++) { // 길이 1
        d[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++) { // 길이 2
        if (a[i] == a[i + 1]) {
            d[i][i + 1] = 1;
        }
    }
    for (int k = 3; k <= n; k++) { // 길이 3 이상
        for (int i = 0; i <= n - k; i++) {
            int j = i + k - 1;
            if (a[i] == a[j] && d[i + 1][j - 1]) {
                d[i][j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // input
    int n, m;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> d(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp
    dp(n, a, d);

    // output
    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << d[s - 1][e - 1] << '\n';
    }

    return 0;
}
