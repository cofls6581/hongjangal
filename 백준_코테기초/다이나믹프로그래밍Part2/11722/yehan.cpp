#include <iostream>
using namespace std;

#define NMAX 1000

int n, ans;
int nums[NMAX] = { 0, };
int DP[NMAX] = { 0 };

int findMaxDP() {
	int max = 0;
	for (int i = 0; i < n; ++i)
		if (max < DP[i]) max = DP[i];
	return max;
}

void solve() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (nums[j] > nums[i] && DP[j] >= DP[i]) DP[i] = DP[j] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 초기화 및 입력
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
		DP[i] = 1;
	}

	// 문제풀기
	solve();
	ans = findMaxDP();

	// 출력 및 종료
	cout << ans;

	return 0;
}
