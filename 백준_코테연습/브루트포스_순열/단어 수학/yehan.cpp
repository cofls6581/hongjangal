#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

char alpha[256]; // alpha[c]: c라는 문자가 어떤 수인지 저장. 아스키 코드

int calc(vector<string> &a, vector<char> &letters, vector<int> &perm) {
	int m = letters.size();
	int sum = 0;
	for (int i = 0; i < m; ++i) alpha[letters[i]] = perm[i];

	for (string s : a) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + alpha[x];
		}
		sum += now;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// 변수 선언, 입력 받기 및 초기화
	int n; cin >> n;
	vector<string> input(n);
	vector<char> letters;
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
		for (char x : input[i]) letters.push_back(x); // letter에 입력받은 모든 단어 넣어주기
	}
	sort(letters.begin(), letters.end()); // letters 정렬
	letters.erase(unique(letters.begin(), letters.end()), letters.end()); // letters 중복 제거
	
	int m = letters.size();
	vector<int> perm;
	for (int i = 9; i > 9 - m; --i) perm.push_back(i);
	sort(perm.begin(), perm.end()); 

	// 문제 풀기
	int ans = 0;
	do {
		int now = calc(input, letters, perm);
		if (ans < now) ans = now;
	} while (next_permutation(perm.begin(), perm.end()));

	/* do while문을 아래와 같이 바꿨을 때 틀렸습니다*/
	/* while (next_permutation(perm.begin(), perm.end())) {
		int now = calc(input, letters, perm);
		if (ans < now) ans = now;
	} */
	

	// 출력 및 종료
	cout << ans << '\n';
	return 0;
}
