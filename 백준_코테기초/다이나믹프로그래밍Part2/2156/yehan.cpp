#include <iostream>
using namespace std;

#define NMAX 10000
#define max(a, b) ((a > b) ? a : b)

int n;
int wine[NMAX + 1] = { 0, };
int DP[NMAX + 1] = { 0, };

void solve() {
	for (int i = 3; i <= n; ++i) {
		DP[i] = (max(DP[i - 1], max(DP[i - 2] + wine[i], DP[i - 3] + wine[i - 1] + wine[i])));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력 받기
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> wine[i];

	// 문제 풀기
	DP[1] = wine[1];
	DP[2] = wine[1] + wine[2];
	solve();

	// 출력 및 종료
	cout << DP[n];

	return 0;
}
