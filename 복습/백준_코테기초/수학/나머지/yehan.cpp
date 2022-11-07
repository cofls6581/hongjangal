/*
나누는 수가 42로 고정되어 있으니 mod라는 배열의 인덱스를 나머지로 활용한다.
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int mod[42] = { 0, };
	int ans = 0;

	for (int i = 0; i < 10; ++i) {
		int input, tmp;
		cin >> input;
		tmp = input % 42;

		if (mod[tmp] == 0) {
			ans += 1;
			mod[tmp] = 1;
		}
	}

	cout << ans << '\n';
	return 0;
}
