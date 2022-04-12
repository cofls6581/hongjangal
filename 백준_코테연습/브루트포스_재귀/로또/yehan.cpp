#include <iostream>
#include <vector>
using namespace std;

vector <int> lotto;

void solve(vector<int> &a, int index, int cnt) {
	// 정답을 찾은 경우
	if (cnt == 6) {
		for (int i = 0; i < 6; ++i)
			cout << lotto[i] << " ";
		cout << '\n';
		return;
	}
	// 불가능한 경우
	int n = a.size();
	if (n == index) return;
	// 다음 경우
	lotto.push_back(a[index]);
	solve(a, index + 1, cnt + 1);
	lotto.pop_back();
	solve(a, index + 1, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int k; cin >> k;
		if (k == 0) break;

		vector <int> a(k);
		for (int i = 0; i < k; ++i) cin >> a[i];

		solve(a, 0, 0);
		cout << '\n';
	}
	return 0;
}
