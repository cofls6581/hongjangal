/*
유클리드의 체를 이용하여 소수를 모두 구한 다음 주어진 숫자를 홀수 소수의 합으로 나타낼 수 있는지 보았다.

문제를 풀며 stack overflow가 발생했었는데, 이와 관련하여 <https://velog.io/@pyh-dotcom/boj6588>에 정리해 두었다.
요약하자면 main함수 내부의 스택 크기에 제한이 있다. 배열의 크기로 10^5까진 가능하였지만 10^6에서는 제한이 생겼다.
해당 배열을 전역 변수로 설정하여 해결할 수 있었다.
*/

#include <iostream>
#include <math.h>
using namespace std;

int primeNum[1000001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	primeNum[1] = 1;
	for (int i = 2; i <= sqrt(1000000); i++) {
		if (primeNum[i] == 1) continue;
		for (int j = 2 * i; j <= 1000000; j += i) {
			primeNum[j] = 1;
		}
	}

	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		
		for (int left = 3; left <= n / 2 + 1; left += 2) {
			int right = n - left;
			if (left > right) {
				cout << "Goldbach's conjecture is wrong.\n";
				break;
			}
			if (primeNum[left]) continue;
			if (primeNum[right] == 0) {
				cout << n << " = " << left << " + " << right << '\n';
				break;
			}
		}
	}
	return 0;
}
