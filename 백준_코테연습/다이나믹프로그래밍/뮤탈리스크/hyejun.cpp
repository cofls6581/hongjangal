#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int d[61][61][61];

int dp(int i, int j, int k) {
    // 음수면 의미 X -> 0으로 변경
    if (i < 0) return dp(0, j, k);
    if (j < 0) return dp(i, 0, k);
    if (k < 0) return dp(i, j, 0);
    // 모두 파괴되었으면 0
    if (i == 0 && j == 0 && k == 0) return 0;

    int& ans = d[i][j][k];
    if (ans != -1) return ans;

    ans = 10000000;
    vector<int> p = { 1, 3, 9 };
    do {
        if (ans > dp(i - p[0], j - p[1], k - p[2])) {
            ans = dp(i - p[0], j - p[1], k - p[2]);
        }
    } while (next_permutation(p.begin(), p.end())); // 공격할 수 있는 경우의 수 (순열)

    ans += 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // input
    int n;
    cin >> n;
    int scv[3] = { 0,0,0 };
    for (int i = 0; i < n; i++) {
        cin >> scv[i];
    }

    // dp, output
    memset(d, -1, sizeof(d));
    cout << dp(scv[0], scv[1], scv[2]) << '\n';

    return 0;
}
