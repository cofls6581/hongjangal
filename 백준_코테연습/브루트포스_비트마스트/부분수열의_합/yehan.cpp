#include <iostream>
using namespace std;

bool check[20 * 100000];
int nums[20];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력 및 초기화
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> nums[i];

	// 문제 풀기
	for (int i = 0; i < (1 << n); ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				sum += nums[j];
			}
		}
		check[sum] = true;
	}

	// 출력 및 종료
	for (int i = 1;; ++i) {
		if (check[i] == false) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}
