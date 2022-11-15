/*
1을 약수로 가지는 수: N / 1개
2를 약수로 가지는 수: N / 2개
...
N을 약수로 가지는 수: N / N개 

문제를 풀면서 시간초과, 자료형 범위 초과 문제를 마주하였다.
문제 풀이 과정은 아래 링크에 정리해 두었다.
https://velog.io/@pyh-dotcom/boj17427
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	long long sum = 0;

	for (int i = 1; i <= n; i++) {
		sum = sum + (n / i) * i;
	}

	cout << sum << '\n';
	return 0;
}
