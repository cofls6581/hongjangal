#include <iostream>
#include <string.h>
using namespace std;

int n, m;
int arr[2005];
int dp[2005][2005];

void bottomUp(int n) {
	for (int i = 1; i <= n; i++) dp[i][i] = 1; // 길이가 1인 경우
	for (int i = 1; i <= n - 1; i++) { // 길이가 2인 경우
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
	}
	for (int k = 3; k <= n; k++) { // 길이가 3 이상인 경우
		for (int i = 1; i <= n - k + 1; i++) { // i: 시작점, j: 끝점
			int j = i + k - 1;
			if (arr[i] == arr[j] && dp[i + 1][j - 1]) {
				dp[i][j] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	bottomUp(n);

	int m; cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}

	return 0;
}
