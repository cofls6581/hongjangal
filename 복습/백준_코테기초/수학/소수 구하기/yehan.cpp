/*
에라토스테네스의 체를 이용하여 소수를 미리 판별해 두었다.
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> primeNum(m + 1, 0); // 소수인 경우 0, 그렇지 않은 경우 
	primeNum[1] = 1;
	for (int i = 2; i <= sqrt(m); i++) {
		if (primeNum[i]) continue;
		for (int j = 2 * i; j <= m; j += i) {
			primeNum[j] = 1;
		}
	}

	for (int i = n; i <= m; i++) {
		if (primeNum[i] == 0) cout << i << '\n';
	}
	return 0;
}
