#include <iostream>
#include <algorithm>
#define A_MAX 100

using namespace std;

int N, M, R, A[A_MAX][A_MAX], F, tmp[A_MAX][A_MAX]; // 가로 N, 세로 M, 연산 개수 R, 배열 A (N, M은 짝수)

void func1() {
	int tmp_x;
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M; j++) {
			tmp_x = A[i][j];
			A[i][j] = A[N - 1 - i][j];
			A[N - 1 - i][j] = tmp_x;
		}
	}
}

void func2() {
	int tmp_x;
	for (int j = 0; j < M / 2; j++) {
		for (int i = 0; i < N; i++) {
			tmp_x = A[i][j];
			A[i][j] = A[i][M - 1 - j];
			A[i][M - 1 - j] = tmp_x;
		}
	}
}

void func3() {
	int tmpN;
	tmpN = N;
	swap(N, M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = A[tmpN - 1 - j][i];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = tmp[i][j];
		}
	}
}

void func4() {
	int tmpM;
	tmpM = M;
	swap(N, M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = A[j][tmpM - 1 - i];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = tmp[i][j];
		}
	}
}

void func5() {
	for (int i = 0; i < N / 2; i++) { //1 -> 2
		for (int j = 0; j < M / 2; j++) {
			tmp[i][j + M / 2] = A[i][j];
		}
	}
	for (int i = 0; i < N / 2; i++) { //2 ->3
		for (int j = M / 2; j < M; j++) {
			tmp[i + N / 2][j] = A[i][j];
		}
	}
	for (int i = N / 2; i < N; i++) { //3->4
		for (int j = M / 2; j < M; j++) {
			tmp[i][j - M / 2] = A[i][j];
		}
	}
	for (int i = N / 2; i < N; i++) { //4->1
		for (int j = 0; j < M / 2; j++) {
			tmp[i - N / 2][j] = A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = tmp[i][j];
		}
	}
}

void func6() {
	for (int i = 0; i < N / 2; i++) { //4 <- 1
		for (int j = 0; j < M / 2; j++) {
			tmp[i + N / 2][j] = A[i][j];
		}
	}
	for (int i = N / 2; i < N; i++) { //3 <- 4
		for (int j = 0; j < M / 2; j++) {
			tmp[i][j + M / 2] = A[i][j];
		}
	}
	for (int i = N / 2; i < N; i++) { //2 <- 3
		for (int j = M / 2; j < M; j++) {
			tmp[i - N / 2][j] = A[i][j];
		}
	}
	for (int i = 0; i < N / 2; i++) { //1 <- 2
		for (int j = M / 2; j < M; j++) {
			tmp[i][j - M / 2] = A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> R;
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	for (i = 0; i < R; i++) {
		cin >> F;
		switch (F) {
		case 1:
			func1();
			break;
		case 2:
			func2();
			break;
		case 3:
			func3();
			break;
		case 4:
			func4();
			break;
		case 5:
			func5();
			break;
		case 6:
			func6();
			break;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
