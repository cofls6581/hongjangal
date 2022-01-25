#include <iostream>
#include <vector>

using namespace std;

int N, S, x, cnt, sum;
vector<int> v;

void solve() {
	for (int i = 1; i < (1 << N); i++) { // i는 000~0001 부터 111~1111(1이 N-1 개)까지.
		sum = 0;
		for (int j = 0; j < N; j++) { // N개의 비트 읽기.
			if ((i & (1 << j)) != 0)
				sum += v[j]; // 해당 비트가 1이면 그 원소를 부분수열에 추가.
		}
		if (sum == S) cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	solve();
	cout << cnt << '\n';
	return 0;
}