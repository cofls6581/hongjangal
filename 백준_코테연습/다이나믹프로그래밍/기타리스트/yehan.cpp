#include <iostream>
#include <algorithm>
using namespace std;

int n, s, m;
int dp[101][1001];
int v[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	// 문제 풀기: DP
	dp[0][s] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j] == 1) {
				if (j + v[i] <= m) dp[i][j + v[i]] = 1;
				if (j - v[i] >= 0) dp[i][j - v[i]] = 1;
			}
		}
	}

	// 출력
	for (int i = m; i >= 0; i--) {
		if (dp[n][i] == 1) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << -1 << '\n';
	return 0;
}
