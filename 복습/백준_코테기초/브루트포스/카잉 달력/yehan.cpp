/*
브루트포스로는 해결할 수 없어 아래 나온 몇가지 조건들을 고려하여 해결하였다.
- 구하고자하는 연도를 M으로 나누었을 때 나머지가 x여야한다.
- 멸망년도에 도달하기 전까지, 구하고자하는 연도와 y값이 대응하는지 살펴본다.
*/

#include <iostream>
using namespace std;

int getGCD(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int getLCM(int a, int b) {
	int gcd = getGCD(a, b);
	return a * b / gcd;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int cnt = getLCM(m, n);
		int year = -1;

		for (int i = x; i <= cnt; i += m) {
			int ny = i % n;
			if (ny == 0) ny = n;
			if (ny == y) {
				year = i;
				break;
			}
		}
		cout << year << '\n';
	}

	return 0;
}
