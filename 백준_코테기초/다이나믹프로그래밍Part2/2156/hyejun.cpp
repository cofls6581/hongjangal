#include <iostream>
#include <algorithm>
#define MAX 10001

using namespace std;

int n, d[MAX], wine[MAX];

void dp() {
	d[1] = wine[1];
	d[2] = wine[1] + wine[2];
	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 1], max(d[i - 2] + wine[i], d[i - 3] + wine[i - 1] + wine[i]));
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	dp();
	cout << d[n] << '\n';
	return 0;
}
