#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int>& nums, vector<char>& sign) {
	for (int i = 0; i < sign.size(); ++i) {
		if (sign[i] == '<' && nums[i] > nums[i + 1]) return false;
		if (sign[i] == '>' && nums[i] < nums[i + 1]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// 변수 선언 및 입력 받기
	int k;
	cin >> k;
	vector<char> sign(k);
	for (int i = 0; i < k; ++i) cin >> sign[i];
	vector<int> small(k + 1);
	vector<int> big(k + 1);
	for (int i = 0; i <= k; ++i) {
		small[i] = i;
		big[i] = 9 - i;
	}

	// 문제 풀기
	while (prev_permutation(big.begin(), big.end())) {
		if (check(big, sign)) break;
	}

	while (next_permutation(small.begin(), small.end())) {
		if (check(small, sign)) break;
	}

	// 출력 및 종료
	for (int i = 0; i <= k; ++i) cout << big[i];
	cout << '\n';
	for (int i = 0; i <= k; ++i) cout << small[i];
	cout << '\n';
	return 0;
}
