#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[61][61][61];

int solve(int i, int j, int k) {
	if (i < 0) return solve(0, j, k);
	if (j < 0) return solve(i, 0, k);
	if (k < 0) return solve(i, j, 0);
	if (i == 0 && j == 0 && k == 0) return 0;

	int& ans = dp[i][j][k];
	if (ans != -1) return ans;
	ans = 10000000;
	vector<int> p = { 1,3,9 };
	do {
		if (ans > solve(i - p[0], j - p[1], k - p[2])) {
			ans = solve(i - p[0], j - p[1], k - p[2]);
		}
	} while (next_permutation(p.begin(), p.end()));
	ans += 1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int scv[3] = { 0, };
	for (int i = 0; i < n; i++) cin >> scv[i];
	memset(dp, -1, sizeof(dp));
	cout << solve(scv[0], scv[1], scv[2]) << '\n';
	return 0;
}
