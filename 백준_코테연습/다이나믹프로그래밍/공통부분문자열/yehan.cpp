#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[4001][4001];
string a, b;
int n, m;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> a >> b;

	// 로직
	n = a.size();
	m = b.size();
	a = " " + a;
	b = " " + b;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = 0;
		}
	}

	// 출력 및 종료
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << '\n';

	return 0;
	
}
