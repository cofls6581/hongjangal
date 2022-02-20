#include <iostream>
#define MAX 300
using namespace std;

int N, M, R, A[MAX][MAX];

void solve() { // 가로 위, 세로 오른쪽, 가로 아래, 세로 왼쪽 순! (시계방향)
	while (R--) {
		int x1 = 0, y1 = 0; // 나중에 x++, y++
		int x2 = N - 1, y2 = 0; // 나중에 x--, y++
		int x3 = N - 1, y3 = M - 1; // 나중에 x--, y--
		int x4 = 0, y4 = M - 1; // 나중에 x++, y--

		while (x1 < x2 && y1 < y4) {
			int tmp = A[x4][y4];
			for (int i = x4; i < x3; i++) { // 가로 위
				A[i][y4] = A[i + 1][y4];
			}
			for (int i = y3; i > y2; i--) { // 세로 오른쪽
				A[x3][i] = A[x3][i - 1];
			}
			for (int i = x2; i > x1; i--) { // 가로 아래
				A[i][y2] = A[i - 1][y2];
			}
			for (int i = y1; i < y4; i++) { // 세로 왼쪽
				A[x1][i] = A[x1][i + 1];
			}
			A[x4][y4 - 1] = tmp; // 마지막에 이자리에 원래의값이 아닌 바뀐값이 들어가게 되므로 저장해둔 tmp 넣기.
			x1++;
			y1++;
			x2--;
			y2++;
			x3--;
			y3--;
			x4++;
			y4--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	solve();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
