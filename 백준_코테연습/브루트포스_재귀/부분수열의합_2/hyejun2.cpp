#include <iostream>
#include <vector>
#define MAX 2000001

using namespace std;

int len;
bool isSum[MAX];

void solve(int subSum, int index, vector<int>& arr) {
	// 반드시 모든 원소에 대해 선택했을 때 합 검사
	if (index == len) {
		// 합 검사
		isSum[subSum] = true;
		return;
	}
	// 다음 호출
	// index번째 선택 O
	solve(subSum + arr[index], index + 1, arr);
	// index번째 선택 X
	solve(subSum, index + 1, arr);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> len;
	vector<int> arr(len);
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	solve(0, 0, arr);
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
