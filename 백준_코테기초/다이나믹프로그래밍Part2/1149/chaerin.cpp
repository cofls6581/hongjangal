#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int dp[MAX][3] = { 0, };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i) {
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];

		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << min(dp[t][0], min(dp[t][1], dp[t][2]));

}