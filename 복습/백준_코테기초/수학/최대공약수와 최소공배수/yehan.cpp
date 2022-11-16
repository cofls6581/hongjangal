/*
유클리드 호제법을 이용하여 최대공배수를 구하고, 구한 최대공배수를 이용하여 최소공배수를 구하였다.
*/

#include <iostream>
using namespace std;

int GCD(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int lcm, gcd;

	gcd = GCD(n, m);
	lcm = n * m / gcd;

	cout << gcd << '\n' << lcm << '\n';
	return 0;
}
