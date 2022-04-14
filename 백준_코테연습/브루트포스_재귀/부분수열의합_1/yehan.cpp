#include <iostream>
using namespace std;

int a[20];
int n, m;
int ans = 0;

void go(int i, int sum) {
	if (i == n) { //  끝까지 탐색했고
		if (sum == m) { // 정답을 찾은 경우
			ans++;
		}
		return;
	}
	go(i + 1, sum + a[i]);
	go(i + 1, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];

	go(0, 0);
	if (m == 0) ans--;
	cout << ans << '\n';
	return 0;
}
