#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// 선언, 입력, 초기화
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int left = 0;
	int right = 0;
	int sum = a[0];
	int ans = n + 1;

	// 문제 풀기
	while (left <= right && right < n) {
		if (sum < m) {
			right++;
			sum += a[right];
		}
		else if (sum >= m) {
			ans = min(ans, right - left + 1);
			sum -= a[left];
			left++;

			if (left > right) {
				right = left;
				sum = a[right];
			}
		}

	}

	// 출력 및 종료
	if (ans == n + 1) ans = 0;
	cout << ans << '\n';
	return 0;
}
