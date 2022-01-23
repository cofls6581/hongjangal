#include <iostream>
#include <vector>

using namespace std;

int N, S, x, cnt, sum;
vector<int> v;

void solve() {
	for (int i = 1; i < (1 << N); i++) { // i�� 000~0001 ���� 111~1111(1�� N-1 ��)����.
		sum = 0;
		for (int j = 0; j < N; j++) { // N���� ��Ʈ �б�.
			if ((i & (1 << j)) != 0)
				sum += v[j]; // �ش� ��Ʈ�� 1�̸� �� ���Ҹ� �κм����� �߰�.
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