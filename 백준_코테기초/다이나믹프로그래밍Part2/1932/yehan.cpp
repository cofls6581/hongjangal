#include <iostream>
using namespace std;

#define NMAX 500

int n, ans;
int tri[NMAX + 1][NMAX + 1] = { 0, };
int DP[NMAX + 1][NMAX + 1] = { 0, };

void findAns() {
	int max = 0;
	for (int i = 0; i <= n; ++i) {
		if (DP[n][i] > max) max = DP[n][i];
	}
	ans = max;
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (DP[i + 1][j] < DP[i][j] + tri[i + 1][j])
				DP[i + 1][j] = DP[i][j] + tri[i + 1][j];
			if (DP[i + 1][j + 1] < DP[i][j] + tri[i + 1][j + 1])
				DP[i + 1][j + 1] = DP[i][j] + tri[i + 1][j + 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력 받기
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)
			cin >> tri[i][j];
	}

	// 문제 풀기
	DP[1][1] = tri[1][1];
	solve();
	findAns();

	// 출력 및 종료
	cout << ans;

	return 0;
}
