#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int left = 0;
	int right = 0;
	int sum = a[0];
	int ans = INT_MAX;
	while (left <= right && right < n) {
		if (sum < s) {
			right++;
			sum += a[right];
		}
		else if (sum == s) {
			int cur = right - left + 1;
			if (cur < ans) ans = cur;
			right++;
			sum += a[right];
		}
		else if(sum > s) {
			int cur = right - left + 1;
			if (cur < ans) ans = cur;
			sum -= a[left];
			left++;
			if (left > right && left < n) {
				right = left;
				sum = a[left];
			}
		}
	}
	if (ans == INT_MAX) ans = 0;
	cout << ans << '\n';
	return 0;
}
