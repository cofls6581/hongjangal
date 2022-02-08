#include <iostream>
#include <string>
#include <algorithm>

#define MAX 10001
using namespace std;
int n;

int arr[MAX] = { 0, };
int dp[MAX] = { 0, };
int maxN = -1;

void func() {

	if (n == 1)
		maxN = arr[1];

	for (int i = 1; i <= n; ++i) {
		dp[i] = arr[i];
		for (int j = 1; j <= i; ++j) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + arr[i]);
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