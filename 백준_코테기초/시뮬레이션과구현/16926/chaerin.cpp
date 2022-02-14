#include <iostream>
#include <string>
#include <algorithm>

#define MAX 301
using namespace std;

int arr[MAX][MAX];
int N, M, R;
int tmp;

void func() {
	int num = min(N, M) / 2;
	for (int i = 0; i < num; ++i) { //둘레 수 만큼 반복
		int prev = arr[i][i];
		int a = i;
		int b = i;
		
		while (a < N - 1 - i) { //왼쪽 돌리기
			tmp = arr[a + 1][b];
			arr[a + 1][b] = prev;
			prev = tmp;
			a++;
		}
	
		while (b < M - 1 -i) { //하단 돌리기
			tmp = arr[a][b + 1];
			arr[a][b + 1] = prev;
			prev = tmp;
			b++;
		}
	
		while (a >= 1 + i) { //오른쪽 돌리기
			tmp = arr[a - 1][b];
			arr[a - 1][b] = prev;
			prev = tmp;
			a--;
		}
		
		while (b >= 1 + i) { //상단 돌리기
			tmp = arr[a][b - 1];
			arr[a][b - 1] = prev;
			prev = tmp;
			b--;
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

	while (R--) {
		func();
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout<< arr[i][j]<<' ';
		}
		cout << '\n';
	}

	return 0;
}
