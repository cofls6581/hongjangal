#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int coins[101] = { 0 };
int dp[10001] = { 0 };
#define unable 10001 // 동전을 가장 많이 사용하는 경우 n=1, k= 10000. 이 때 사용하는 동전 10000개. 이보다 동전을 더 많이 사용할 수 없음

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> coins[i];
	
	for (int i = 0; i <= k; i++) dp[i] = unable;

	// 로직
	dp[0] = 0; // 0원을 만드는 방법: 어떤 동전도 선택하지 않는다.
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
		}
	}

	// 출력 및 종료
	if (dp[k] == 10001) cout << -1 << '\n';
	else cout << dp[k] << '\n';

	return 0;
}
