#include <iostream>

using namespace std;

int N, ans;
int w[10];
bool isRemoved[10];

// 구슬이 3개 남았을 때가 마지막. (1,3번째 에너지 합치고 끝)
void solve(int cnt, int energy) {
	// 성공한 경우
	if (cnt == N - 2) {
		if (energy > ans) ans = energy;
		return;
	}
	// 실패한 경우 없음
	for (int i = 1; i < N - 1; i++) {
		if (!isRemoved[i]) {
			int prev = i - 1, next = i + 1;
			while (isRemoved[prev] && prev > 0) {
				prev--;
			}
			while (isRemoved[next] && next < N - 1) {
				next++;
			}
			// 다음 호출 전 처리
			isRemoved[i] = true;
			// 다음 호출
			solve(cnt + 1, energy + w[prev] * w[next]);
			// 다음 호출 후 처리
			isRemoved[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}
	solve(0, 0);
	cout << ans << '\n';
	return 0;
}
