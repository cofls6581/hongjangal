#include <iostream>
#include <algorithm>
using namespace std;

int N, ans; // 1 <= N <= 15
int T[16];
int P[16];

void solve(int cur_day, int total_profit) {
	// 재귀 종료 조건
	if (cur_day >= N + 1) {
		ans = max(ans, total_profit);
		return;
	}
	//재귀
	if (cur_day + T[cur_day] <= N + 1)
		solve(cur_day + T[cur_day], total_profit + P[cur_day]); // 해당 날에 상담을 하고, 해당 상담에 걸리는 일수만큼 넘어가는 경우
	if (cur_day + 1 <= N + 1)
		solve(cur_day + 1, total_profit); // 해당 날에 상담을 하지 않고, 다음날로 넘어가는 경우
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	solve(1, 0);
	cout << ans << '\n';
	return 0;
}