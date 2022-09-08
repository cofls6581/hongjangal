#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력 및 초기화
	cin >> n;
	dp[0] = 0;

	// 로직
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1; // A를 출력하는 경우
		for (int j = 1; j <= i - 2; j++) {
			dp[i] = max(dp[i], dp[i - (j + 2)] * (j + 1)); // A를 누르는 경우와 ctrl 누르는 경우 비교
		}
	}


	// 출력 및 종료
	cout << dp[n] << '\n';

	return 0;
}
