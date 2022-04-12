#include <iostream>
#include <vector>

using namespace std;

vector<int> six;

void solve(vector<int> &s, int index, int cnt) { // index: 선택할지 말아야할지 결정해야하는 인덱스 / cnt: 현재까지 선택한 개수
	// 정답을 찾은 경우
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << six[i] << ' ';
		}
		cout << '\n';
		return;
	}
	// 불가능한 경우
	if (index == s.size()) return;
	// 다음 호출
	six.push_back(s[index]);
	solve(s, index + 1, cnt + 1);
	six.pop_back();

	solve(s, index + 1, cnt);
}

int main() {
	while (1) {
		int k;
		cin >> k;
		if (k == 0) break;
		vector<int> s(k); // 사이즈 미리 안정하고 인덱스 접근시 에러 발생
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		solve(s, 0, 0);
		cout << '\n';
	}
	return 0;
}
