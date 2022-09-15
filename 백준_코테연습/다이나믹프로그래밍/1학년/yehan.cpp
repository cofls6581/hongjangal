#include <iostream>
using namespace std;

int n;
int nums[101];
long long dp[101][21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];

	// 로직
	dp[0][nums[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < 21; j++) {
			if(j-nums[i]>=0) dp[i][j] += dp[i - 1][j - nums[i]];
			if(j+nums[i] < 21) dp[i][j] += dp[i - 1][j + nums[i]];
		}
	}

	// 출력 및 종료
	cout << dp[n - 2][nums[n - 1]] << '\n';
	return 0;
}
