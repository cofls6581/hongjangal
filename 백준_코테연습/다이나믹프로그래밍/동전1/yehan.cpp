#include <iostream>
using namespace std;

int n, k;
int coins[101] = { 0 };
int dp[10001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> coins[i];

	// 로직
	dp[0] = 1; // 0원을 만드는 방법: 어떤 동전도 선택하지 않는다.
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}

	// 출력 및 종료
	cout << dp[k] << '\n';
	return 0;
}
