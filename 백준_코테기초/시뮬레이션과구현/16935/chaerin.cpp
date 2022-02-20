#include <iostream>
#include <string>
#include <algorithm>

#define MAX 101
#define MAXR 1001
using namespace std;

int arr[MAX][MAX];
int copyArr[MAX][MAX];

int N, M,R;
int input[MAXR] = {0,};
int tmp;

void copy() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			copyArr[i][j] = arr[i][j];
		}
	}
}


void f1() { //상하반전
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M; j++) {
			tmp = arr[N - 1 - i][j];
			arr[N - 1 - i][j] = arr[i][j];
			arr[i][j] = tmp;
		}
	}
}
void f2() {//좌우반전
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < M/2; j++) {
			tmp = arr[i][M-1-j];
			arr[i][M - 1 - j] = arr[i][j];
			arr[i][j] = tmp;
		}
	}
}
void f3() {//시계방향 90도 회전
	copy();
	swap(N, M);
	for (int i = 0; i <M ; ++i) {
		for (int j = 0; j < N; ++j) {
			arr[j][i] = copyArr[M - 1 - i][j];
		}
	}
}
void f4() { //반시계방향 90도 회전
	f3();
	f1();
	f2();
}
void f6() {//4등분 시계 방향 90도 회전
	copy();
	//4to1
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[i + N / 2][j] = copyArr[i][j];
		}
	}
	//3to4
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[i][j + M / 2] = copyArr[i][j];
		}
	}

	//2to3
	for (int i = N / 2; i < N; i++) {
		for (int j = M / 2; j < M; j++) {
			arr[i - N / 2][j] = copyArr[i][j];
		}
	}

	//1to2
	for (int i = 0; i < N / 2; i++) {
		for (int j = M / 2; j < M; j++) {
			arr[i][j - M / 2] = copyArr[i][j];
		}
	}
}
void f5() {//4등분 반시계 방향 90도 회전
	copy();
	//1to4
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < M/ 2; j++) {
			arr[i - N / 2][j] = copyArr[i][j];
		}
	}
	//2to1
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[i][j + M / 2] = copyArr[i][j];
		}
	}
	//3to2
	for (int i = 0; i < N / 2; i++) {
		for (int j = M / 2; j < M; j++) {
			arr[i + N / 2][j] = copyArr[i][j];
		}
	}
	//4to3
	for (int i = N / 2; i < N; i++) {
		for (int j = M / 2; j < M; j++) {
			arr[i][j - M / 2] = copyArr[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> M >> R;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < R; ++i) 
		cin >> input[i];


	for (int i = 0; i < R; ++i) {
		switch (input[i]) {
		case 1:
			f1();
			break;
		case 2:
			f2();
			break;
		case 3:
			f3();
			break;
		case 4:
			f4();
			break;
		case 5:
			f5();
			break;
		case 6:
			f6();
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
