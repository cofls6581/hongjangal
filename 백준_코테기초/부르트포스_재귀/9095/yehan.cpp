#include <iostream>
using namespace std;

int DP[12] = { 0 };

int recursive(int i) {
	if (i == 1) return 1;
	if (i == 2) return 2;
	if (i == 3) return 4;
	DP[i] = recursive(i - 1) + recursive(i - 2) + recursive(i - 3);

	return DP[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int testcase; cin >> testcase;
	int max_prev_n = 3, cur_n;

	DP[0] = 0;
	DP[1] = 1; DP[2] = 2; DP[3] = 4;

	while (testcase--) {
		cin >> cur_n;
		
		if (max_prev_n < cur_n) recursive(cur_n);

		cout << DP[cur_n] << '\n';

		if (max_prev_n < cur_n) max_prev_n = cur_n;
	}
	return 0;
}
