/*
구해야 할 숫자 N은 가장 작은 약수와 가장 큰 약수의 곱이다.
따라서 벡터에 진짜 약수를 입력받고 정렬하여 구하였다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) cin >> num[i];
	int ans;

	sort(num.begin(), num.end());
	ans = num[0] * num[n - 1];

	cout << ans << '\n';
}
