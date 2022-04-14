#include <iostream>
#include <vector>
#define MAX 2000001

using namespace std;

int len;
bool isSum[MAX];

void solve(int subLen, int index, int cnt, vector<int>& arr, vector<int>& sub) {
	// 정해진 개수만큼 부분 수열 만든 경우
	if (cnt == subLen) {
		int result = 0;
		for (int i = 0; i < subLen; i++) {
			result += sub[i];
		}
		isSum[result] = true;
		return;
	}
	// 불가능한 경우
	if (index == len) return;
	// 다음 호출
	sub.push_back(arr[index]);
	solve(subLen, index + 1, cnt + 1, arr, sub);
	sub.pop_back();

	solve(subLen, index + 1, cnt, arr, sub);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> len;
	vector<int> arr(len);
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= len; i++) { // 부분 수열의 길이
		vector<int> sub;
		solve(i, 0, 0, arr, sub);
	}
	int i = 1, minNumber;
	while (1) {
		if (isSum[i] == false) {
			minNumber = i;
			break;
		}
		i++;
	}
	cout << minNumber << '\n';
	return 0;
}
