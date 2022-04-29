#include <iostream>

using namespace std;

int N, M;
int arr[500][500];
bool check[500][500];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 0;

void solve(int x, int y, int cnt, int sum) { // 기준 칸에서 시작해서 연속으로 3칸을 선택.
	// 성공한 경우
	if (cnt == 4) {
		if (sum > ans) ans = sum;
		return;
	}
	// 실패한 경우
	if (x < 0 || x > N - 1 || y < 0 || y > M - 1) return;
	if (check[x][y]) return;
	// 다음 호출 전 준비
	check[x][y] = true;
	// 다음 호출
	for (int i = 0; i < 4; i++) {
		solve(x + dx[i], y + dy[i], cnt + 1, sum + arr[x][y]);
	}
	// 다음 호출 후 처리
	check[x][y] = false; // dfs와 다르게 같은 칸을 여러번 방문하므로.
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			solve(i, j, 0, 0);

			if (i + 2 < N) { // 세로형 (ㅏ, ㅓ)
				int tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
				if (j + 1 < M) {
					int sum1 = tmp + arr[i + 1][j + 1];
					if (sum1 > ans) ans = sum1;
				}
				if (j - 1 >= 0) {
					int sum2 = tmp + arr[i + 1][j - 1];
					if (sum2 > ans) ans = sum2;
				}
			}
			if (j + 2 < M) { // 가로형 (ㅗ, ㅜ)
				int tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
				if (i - 1 >= 0) {
					int sum1 = tmp + arr[i - 1][j + 1];
					if (sum1 > ans) ans = sum1;
				}
				if (i + 1 < N) {
					int sum2 = tmp + arr[i + 1][j + 1];
					if (sum2 > ans) ans = sum2;
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
