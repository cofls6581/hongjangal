#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001];
int st[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력 및 초기화
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();


	// 로직
	a = " " + a;
	b = " " + b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				st[i][j] = 1;
			}
			else {
				if (dp[i - 1][j] < dp[i][j - 1]) {
					dp[i][j] = dp[i][j - 1];
					st[i][j] = 2;
				}
				else {
					dp[i][j] = dp[i - 1][j];
					st[i][j] = 3;
				}
			}
		}
	}


	// 출력 및 종료
	cout << dp[n][m] << '\n';
	string ans = "";
	while (n > 0 && m > 0) {
		if (st[n][m] == 1) {
			ans += a[n];
			n--; m--;
		}
		else if (st[n][m] == 2) {
			m--;
		}
		else {
			n--;
		}
	}
	reverse(ans, ans.begin(), ans.end());
	cout << ans << '\n';
	return 0;
}
