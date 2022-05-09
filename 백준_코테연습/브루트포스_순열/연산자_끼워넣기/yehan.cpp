#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc(vector<int>& a, vector<int>& b) {
	int n = a.size();
	int ans = a[0];
	for (int i = 1; i < n; ++i) {
		if (b[i - 1] == 0) ans = ans + a[i];
		else if (b[i - 1] == 1) ans = ans - a[i];
		else if (b[i - 1] == 2) ans = ans * a[i];
		else ans = ans / a[i];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 선언 및 입력
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i) cin >> nums[i];

	vector<int> operators;
	for (int i = 0; i < 4; ++i) {
		int cnt;
		cin >> cnt;
		for (int k = 0; k < cnt; ++k) operators.push_back(i);
	}
	
	// 문제 풀기
	vector<int> result;
	do {
		int tmp = calc(nums, operators);
		result.push_back(tmp);
	} while (next_permutation(operators.begin(), operators.end()));

	auto ans = minmax_element(result.begin(), result.end());

	// 출력 및 종료
	cout << *ans.second << '\n';
	cout << *ans.first << '\n';
	return 0;

}
