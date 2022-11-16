/*
모든 가능한 경우에 대해 미리 계산하여 두고 결과 값을 출력한다.
*/

#include <iostream>
using namespace std;

#define MAX 1000001

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int testcase, n;
	long long g[MAX] = { 0, };
	cin >> testcase;

	// f(A) 구하기 - 각 숫자의 모든 약수의 합 구하기
	for (int i = 1; i < MAX; i++) {
		for (int j = i; j < MAX; j+=i) {
			g[j] += i;
		}
	}
	
	// g(x) 구하기 - x보다 작은 모든 y의 f(y) 합 구하기
	for (int i = 2; i < MAX; i++) {
		g[i] += g[i - 1];
	}


	while (testcase--) {
		cin >> n;
		cout << g[n] << '\n';
	}

	return 0;
}
