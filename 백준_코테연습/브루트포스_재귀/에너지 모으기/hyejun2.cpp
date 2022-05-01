#include <iostream>
#include <vector>

using namespace std;

// 구슬이 3개 남았을 때가 마지막. (1,3번째 에너지 합치고 끝)
int solve(vector<int> &arr) {
	// 성공한 경우 (구슬이 2개 남았으면 0 리턴하면서 종료)
	int size = arr.size();
	if (size == 2) return 0;
	int ans = 0;
	for (int i = 1; i < size - 1; i++) {
		int energy = arr[i - 1] * arr[i + 1];
		vector<int> newArr(arr);
		newArr.erase(newArr.begin() + i); // 구슬 제거
		// 다음 호출
		energy += solve(newArr);

		// 최대값 갱신
		if (ans < energy) {
			ans = energy;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int> w(N);
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}
	cout << solve(w) << '\n';
	return 0;
}
