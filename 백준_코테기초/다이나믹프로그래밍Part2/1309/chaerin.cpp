#include <iostream>
#include <algorithm>

#define MAX 100001
#define modN 9901

using namespace std;

long long dp[MAX][3];


void bottomup(int k) {

	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= k; ++i) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % modN;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % modN;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % modN;
	}

}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int k;
	cin >> k;

	bottomup(k);

	cout << (dp[k][0] + dp[k][1] + dp[k][2]) % modN;

	return 0;
}