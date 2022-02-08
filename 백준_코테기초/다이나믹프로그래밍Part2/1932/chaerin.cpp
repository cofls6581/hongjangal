#include <iostream>
#include <string>
#include <algorithm>

#define MAX 501
using namespace std;
int n;

int dp[MAX][MAX];
int maxN = 0;

void func() {

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (maxN < dp[n][i])
			maxN = dp[n][i];
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> dp[i][j];
	}

	func();

	cout << maxN << '\n';

	return 0;
}