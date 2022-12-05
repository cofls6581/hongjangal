/*
에라토스테네스의 체를 이용하여 소수인지 미리 판별해 두었다.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int primeNum[1001] = { 0, }; // 소수인 경우 0, 그렇지 않은 경우 
	primeNum[1] = 1;
	for (int i = 2; i <= sqrt(1000); i++) {
		if (primeNum[i]) continue;
		for (int j = 2 * i; j <= 1000; j += i) {
			primeNum[j] = 1;
		}
	}

	int n; cin >> n;
	int num;
	int ans = 0;
	while (n--) {
		cin >> num;
		if (primeNum[num] == 0) ans++;
	}
	cout << ans << '\n';
	return 0;
}
