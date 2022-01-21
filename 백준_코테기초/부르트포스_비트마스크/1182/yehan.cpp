#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, S;
	int sum, ans = 0;
	int nums[21];

	cin >> N >> S;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	for (int i = 1; i < (1 << N); ++i) {
		sum = 0;
		for (int j = 0; j < N; ++j) {
			if ((1 << j) & i)
				sum += nums[j];
		}
		if (sum == S)
			ans++;
	}

	cout << ans;
}