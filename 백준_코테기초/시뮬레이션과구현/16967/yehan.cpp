#include <iostream>
using namespace std;

#define MAX 301

int H, W, X, Y;
int A[MAX][MAX] = { 0, };
int B[2 * MAX][2 * MAX] = { 0, };

void solve() {
	// 겹치지 않는 X개 행 채우기
	for (int i = 0; i < X; ++i) {
		for (int j = 0; j < W; ++j) {
			A[i][j] = B[i][j];
		}
	}

	// 겹치지 않는 Y개 열 채우기
	for (int i = X; i < H; ++i) {
		for (int j = 0; j < Y; ++j) {
			A[i][j] = B[i][j];
		}
	}

	// 겹치는 부분 채우기
	for (int i = X; i < H; ++i) {
		for (int j = Y; j < W; ++j) {
			A[i][j] = B[i][j] - A[i - X][j - Y];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 선언 및 입력
	cin >> H >> W >> X >> Y;
	for (int i = 0; i < H + X; ++i) {
		for (int j = 0; j < W + Y; ++j) {
			cin >> B[i][j];
		}
	}

	// 문제 풀기
	solve();

	// 출력 및 종료
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
