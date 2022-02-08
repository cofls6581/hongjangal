#include <iostream>
#include <string>
#include <algorithm>

#define MAX 10001
using namespace std;
int n;

int arr[MAX];
int dp[MAX];
int maxN = -1;

void func() {

	if (n == 1) {
		maxN = 1;
		return;
	}

	for (int i = 1; i <= n; ++i) {
		dp[i] = 1;
		for (int j = 1; j <= i; ++j) {
			if (arr[i] < arr[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		maxN = max(dp[i], maxN);
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	func();

	cout << maxN << '\n';

	return 0;
}