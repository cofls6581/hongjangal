#include <iostream>
#include <vector>

using namespace std;

int dp(int i, int j, vector<int> &a, vector<vector<int>> &d) {
    if (i == j) {
        return 1;
    }
    else if (i + 1 == j) {
        if (a[i] == a[j]) return 1;
        else return 0;
    }
    // 메모이제이션
    if (d[i][j] >= 0) {
        return d[i][j];
    }
    if (a[i] != a[j]) {
        return d[i][j] = 0;
    }
    else {
        return d[i][j] = dp(i + 1, j - 1, a, d);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> d(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << dp(s - 1, e - 1, a, d) << '\n';
    }

    return 0;
}
