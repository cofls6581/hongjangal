#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int count(int learn, vector<int>& word) { // 읽을 수 있는 단어 개수 세기
	int cnt = 0;
	int size = word.size();
	for (int i = 0; i < size; i++) {
		if ((word[i] & ((1 << 26) - 1 - learn)) == 0) {
			cnt++;
		}
	}
	return cnt;
}

int solve(int index, int k, int learn, vector<int> &word) {
	// 실패한 경우
	if (k < 0) {
		return 0;
	}
	// 성공한 경우
	if (index == 26) {
		return count(learn, word);
	}
	// 다음 호출
	int ans = 0;
	// index번째 알파벳을 배움
	int tmp = solve(index + 1, k - 1, learn | (1 << index), word);
	if (ans < tmp) {
		ans = tmp;
	}
	// index번째 알파벳을 안배움
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') { // a,n,t,i,c 는 무조건 배워야하므로
		tmp = solve(index + 1, k, learn, word);
		if (ans < tmp) {
			ans = tmp;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K;
	cin >> N >> K;
	vector<int> word(N); // 단어 자체를 저장하는 것이 아니라 단어에 포함된 알파벳을 비트로 저장
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (char x : s) {
			word[i] |= (1 << (x - 'a'));
		}
	}
	cout << solve(0, K, 0, word) << '\n';
	return 0;
}
