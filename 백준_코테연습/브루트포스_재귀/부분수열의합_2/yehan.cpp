#include <iostream>
using namespace std;

bool c[20 * 100000 + 10];
int a[20];
int n;

void go(int i, int sum) {
	if (i == n) { // 마지막 인덱스까지 더한 경우
		c[sum] = true;
		return;
	}
	go(i + 1, sum + a[i]); // 포함하는 경우
	go(i + 1, sum); // 포함하지 않는 경우
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	go(0, 0);

	for (int i = 1;; ++i) {
		if (c[i] == false) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}
