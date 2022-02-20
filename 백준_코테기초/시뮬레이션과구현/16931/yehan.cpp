#include <iostream>
using namespace std;

#define MAX 101

int N, M, ans = 0;
int blocks[MAX][MAX] = { 0, };
int surface[MAX][MAX] = { 0, };

void Solve() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			// 바닥면 블록
			if (blocks[i][j]) surface[i][j]++;
			// 위쪽 블록과 블록 수 비교
			if (blocks[i][j] > blocks[i - 1][j])
				surface[i][j] += (blocks[i][j] - blocks[i - 1][j]);
			// 오른쪽 블록과 블록 수 비교
			if (blocks[i][j] > blocks[i][j + 1])
				surface[i][j] += (blocks[i][j] - blocks[i][j + 1]);
		}
	}
}

void AddAns() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			ans += surface[i][j];
		}
	}
	ans *= 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> blocks[i][j];
		}
	}

	// 문제 풀기
	Solve();
	AddAns();

	// 출력 및 선언
	cout << ans;

	return 0;
}
