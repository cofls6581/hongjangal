#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> calc(vector<int>& a, int index, int cur, int plus, int minus, int mul, int div) {
	/* 끝까지 탐색한 경우 */
	int n = a.size();
	if (index == n) return make_pair(cur, cur); // (최대, 최소)

	/* 다음 호출 */
	vector<pair<int, int>> res; // 함수의 리턴값 모두 저장
	if (plus > 0) res.push_back(calc(a, index + 1, cur + a[index], plus - 1, minus, mul, div));
	if (minus > 0) res.push_back(calc(a, index + 1, cur - a[index], plus, minus - 1, mul, div));
	if (mul > 0) res.push_back(calc(a, index + 1, cur * a[index], plus, minus, mul - 1, div));
	if (div > 0) res.push_back(calc(a, index + 1, cur / a[index], plus, minus, mul, div - 1));

	/* 최대, 최소 찾기 */
	auto ans = res[0];
	for (auto p : res) {
		if (ans.first < p.first) ans.first = p.first; // 최댓값 저장
		if (ans.second> p.second) ans.second = p.second; // 최댓값 저장
	}

	return ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;

	auto p = calc(a, 1, a[0], plus, minus, mul, div);
	
	cout << p.first << '\n';
	cout << p.second << '\n';
	return 0;
}
