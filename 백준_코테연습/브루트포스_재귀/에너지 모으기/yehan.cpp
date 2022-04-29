#include <iostream>
#include <vector>
using namespace std;

int go(vector<int>& a) {
	int n = a.size();
	if (n == 2) return 0; // 정답을 찾은 경우: 더 이상 합칠 수 없다.

	int ans = 0;
	for (int i = 1; i < n - 1; ++i) { // 다음 경우
		int energy = a[i - 1] * a[i + 1];
		vector<int> b(a);
		b.erase(b.begin() + i);
		energy += go(b);
		if (ans < energy) ans = energy;
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	cout << go(a) << '\n';
	return 0;
}
