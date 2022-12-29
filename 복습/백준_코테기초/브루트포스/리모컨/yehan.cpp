/*
+, -만 눌러서 목표 채널에 도달한 경우,
특정 채널로 이동하여 +,-을 눌러 목표 채널에 도달한 경우
로 나누어 계산
*/

#include <iostream>
#include <math.h>
using namespace std;

int n, m;
int remote[10]; // 정상작동하는 버튼은 0, 고장난 버튼은 1

int check(int n) {
	if (n == 0) {
		if (remote[0]) return 0;
		else return 1;
	}

	int cnt = 0;
	while (n > 0) {
		if (remote[n % 10]) return 0;
		n = n / 10;
		cnt++;
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int button; cin >> button;
		remote[button] = 1;
	}

	int ans = abs(n - 100); // 시작점 1--에서 +,-만 눌러서 목표채널 도달

	for (int i = 0; i <= 1000000; i++) {
		int cnt = check(i);
		if (cnt > 0) {
			int press = abs(i - n);
			if (ans > press + cnt) ans = press + cnt;
		}
	}
	cout << ans << '\n';
	return 0;
}
