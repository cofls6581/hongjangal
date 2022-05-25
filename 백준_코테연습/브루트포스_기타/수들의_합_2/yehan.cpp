#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// 선언, 입력, 초기화
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int left = 0;
	int right = 0;
	int sum = a[0];
	int ans = 0;
	
	// 문제 풀기
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
			if (left > right && left < n) { // 배열이 [3, 5, 10, 2, 6], M == 8인 경우 생각해보기
				right = left;
				sum = a[left];
			}
		}
	}

	// 출력 및 종료
	cout << ans << '\n';
	return 0;
}
