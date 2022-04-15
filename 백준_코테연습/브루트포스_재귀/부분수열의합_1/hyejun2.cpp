#include <iostream>
#include <vector>

using namespace std;

int len, sum, ans = 0;

void solve(vector<int>& arr, int subSum, int index) {
	// 반드시 모든 원소에 대해 선택했을 때 합 검사
	if (index == len) {
		// 합 검사
		if (subSum == sum) {
			ans++;
		}
		return;
	}
	// 다음 호출
	// index번째 선택 O
	solve(arr, subSum + arr[index], index + 1);
	// index번째 선택 X
	solve(arr, subSum, index + 1);
}

int main() {
	cin >> len >> sum;
	vector<int> arr(len);
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	solve(arr, 0, 0);
	if (sum == 0) {
		ans--;
	}
	cout << ans << '\n';
	return 0;
}
