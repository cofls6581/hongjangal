#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int solve(vector<int> &a, vector<int> &op) {
	int result = a[0];
	int size = op.size();
	for (int i = 0; i < size; i++) {
		if (op[i] == 0) {
			result += a[i + 1];
		}
		else if (op[i] == 1) {
			result -= a[i + 1];
		}
		else if (op[i] == 2) {
			result *= a[i + 1];
		}
		else {
			result /= a[i + 1];
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	vector<int> op;
	int x;
	for (int i = 0; i < 4; i++) {
		cin >> x;
		for (int j = 0; j < x; j++) {
			op.push_back(i);
		}
	}
	// 원래 다음 순열을 구하기 전에 정렬해야하지만 이 문제에서는 위에서 0,1,2,3 순으로 들어가므로 정렬 생략 가능
	vector<int> t;
	do {
		int tmp = solve(a, op);
		t.push_back(tmp);
	} while (next_permutation(op.begin(), op.end()));
	auto ans = minmax_element(t.begin(), t.end());
	cout << *ans.second << '\n';
	cout << *ans.first << '\n';
	return 0;
}
