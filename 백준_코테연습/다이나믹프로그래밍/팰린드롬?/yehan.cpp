#include <iostream>
#include <string.h>
using namespace std;

int n, m;
int arr[2005];
int dp[2005][2005];

int topDown(int i, int j) {
	if (i == j) return 1; // 길이가 1인 경우

	else if (i + 1 == j) { // 길이가 2인 경우
		if (arr[i] == arr[j]) return dp[i][j] = 1;
		else return dp[i][j] = 0;
	}

	if (dp[i][j] >= 0) return dp[i][j]; // Memozation

	if (arr[i] != arr[j]) return dp[i][j] = 0;
	else return dp[i][j] = topDown(i + 1, j - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	memset(dp, -1, sizeof(dp));

	int m; cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << topDown(s, e) << '\n';
	}

	return 0;
}
