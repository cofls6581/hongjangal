#include <iostream>
#include <vector>

using namespace std;

int len, sum, ans = 0;

void solve(vector<int>& arr, int subLen, int cnt, int index, vector<int>& sub) {
	// 정답 찾은 경우
	if (cnt == subLen) {
		// 합 검사
		int result = 0;
		for (int i = 0; i < subLen; i++) {
			result += sub[i];
		}
		if (result == sum) ans++;
		return;
	}
	// 불가능한 경우
	if (index == len) return;
	// 다음 호출
	// index번째 선택 O
	sub.push_back(arr[index]);
	solve(arr, subLen, cnt + 1, index + 1, sub);
	sub.pop_back();
	// index번째 선택 X
	solve(arr, subLen, cnt, index + 1, sub);
}

int main() {
	cin >> len >> sum;
	vector<int> arr(len);
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= len; i++) {
		vector<int> sub;
		solve(arr, i, 0, 0, sub);
	}
	cout << ans << '\n';
	return 0;
}
