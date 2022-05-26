#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int left = 0;
	int right = 0;
	int sum = a[0];
	int ans = 0;
	while (left <= right && right < n) {
		if (sum < m) {
			right++;
			sum += a[right];
		}
		else if (sum == m) {
			ans++;
			right++;
			sum += a[right];
		}
		else if (sum > m) {
			sum -= a[left];
			left++;
			if (left > right && left < n) {
				right = left;
				sum = a[left];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
