#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;

pair<int, int> solve(int index, int result, int plus, int minus, int multi, int divide) {
	// 정답 만든 경우
	if (index == N) {
		return make_pair(result, result);
	}
	// 다음 호출: 각 자리의 연산자가 +, -, *, / 인 경우 각 4가지에 대해 호출
	// 연산 결과를 저장할 벡터 생성
	vector<pair<int, int>> res;
	if (plus > 0)
		res.push_back(solve(index + 1, result + arr[index], plus - 1, minus, multi, divide));
	if (minus > 0)
		res.push_back(solve(index + 1, result - arr[index], plus, minus - 1, multi, divide));
	if (multi > 0)
		res.push_back(solve(index + 1, result * arr[index], plus, minus, multi - 1, divide));
	if (divide > 0)
		res.push_back(solve(index + 1, result / arr[index], plus, minus, multi, divide - 1));
	// 최대값, 최소값 찾기
	pair<int, int> ans = res[0]; // ans: 최대값, 최솟값의 pair
	for (auto i : res) {
		if (ans.first < i.first) ans.first = i.first;
		if (ans.second > i.second) ans.second = i.second;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		arr.push_back(x);
	}
	int plus, minus, multi, divide;
	cin >> plus >> minus >> multi >> divide;
	auto answer = solve(1, arr[0], plus, minus, multi, divide);
	cout << answer.first << '\n' << answer.second << '\n';
	return 0;
}
