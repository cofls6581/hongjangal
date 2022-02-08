#include <iostream>
#include <string>
#include <algorithm>

#define MAX 10001
using namespace std;
int n;

int arr[MAX] = {0,};
int dp[MAX] = {0,};
int maxN = -1;

void func() {
	dp[0] = arr[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1]+arr[2];

	for (int i = 3; i <= n; ++i) 
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], max(dp[i - 2]+arr[i], dp[i - 1]));

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> arr[i];

	func();
	cout << dp[n] << '\n';
	return 0;
}
