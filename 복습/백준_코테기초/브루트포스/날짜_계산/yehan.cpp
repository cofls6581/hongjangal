/*
테스트 해 볼 케이스가 약 8000(15*28*19)개 정도밖에 없으므로 부르트포스로 해결
주어진 숫자에서 1씩 빼가며 확인
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int e, s, m;
	int year = 0;
	cin >> e >> s >> m;

	while (1) {
		year++;
		e--; s--; m--;
		if (e == 0 && s == 0 && m == 0) break;

		if (e <= 0) e = 15;
		if (s <= 0) s = 28;
		if (m <= 0) m = 19;
	}

	cout << year << '\n';
	return 0;
}
