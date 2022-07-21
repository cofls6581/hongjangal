#include <iostream>
using namespace std;

int maze[1001][1001];
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maze[i][j];
		}
	}

	// 문제풀기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + maze[i][j];
		}
	}

	// 출력 및 종료
	cout << dp[n][m] << '\n';
	return 0;
}
