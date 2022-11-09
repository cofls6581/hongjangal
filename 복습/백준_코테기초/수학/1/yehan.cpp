/*
1로만 이루어진 숫자가 계속 커지다 보면 int형의 범위를 벗어날 수 있다. => 계산 중간중간에 mod 연산을 계속 사용하자.
1로만 이루어진 수는 어떻게 만들까? => 1부터 시작해서 *10+1 반복하자.
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;

	while (cin >> n) {
		int cnt = 1; // 자리수
		int num = 1; // 1로만 이루어진 수

		while (1) {
			if (num % n == 0) {
				cout << cnt << '\n';
				break;
			}
			num = ((num * 10) + 1) % n;
			cnt++;
		}
		
	}
	
	return 0;
}
