/* 두 가지 방법으로 풀이
1. 한 자리 숫자 개수 + 두 자리 숫자 개수 + ...
  코드가 한 눈에 들어오지 않아 새로운 방법을 고민하였다.
2. 일의 자리 개수 + 십의 자리 개수 + ..
  코드가 훨씬 간결하다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	/* 1번 풀이
	int n; cin >> n;
	int ans = 0;
	int digit = 1; // 자릿수
	int start = 1; // 각 자릿수의 첫 숫자(1, 10, 100 ...)

	while (1) {
		int end = start * 10 - 1; // 각 자릿수의 마지막 숫자(9, 99, 999 ...)
		int smaller = min(end, n);
		ans += digit * (smaller - start + 1);
		digit++;
		start *= 10;
		if (smaller == n) break;
	}
	*/

	// 2번 풀이
	int  n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i *= 10) {
		ans += n - i + 1;
	}

	cout << ans << '\n';
	return 0;
}
