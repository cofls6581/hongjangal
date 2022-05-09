#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N; // 단어 개수
char alpha[128]; // 해당 인덱스의 알파벳이 어떤 숫자로 바뀌는지 저장 (인덱스는 ASCII 코드)

int calc(vector<string>& wordArr, vector<char>& alphabets, vector<int>& numbers) {
	int s = alphabets.size();
	int sum = 0;
	for (int i = 0; i < s; i++) {
		alpha[alphabets[i]] = numbers[i]; // 알파벳을 숫자로 치환
	}

	for (string word : wordArr) {
		int now = 0;
		for (char x : word) {
			now = now * 10 + alpha[x];
		}
		sum += now;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<string> wordArr(N);
	vector<char> alphabets; // 단어에 어떤 알파벳들이 있는지
	for (int i = 0; i < N; i++) {
		cin >> wordArr[i];
		for (char letter : wordArr[i]) {
			alphabets.push_back(letter);
		}
	}

	// alphabets 벡터 중복 제거
	sort(alphabets.begin(), alphabets.end());
	alphabets.erase(unique(alphabets.begin(), alphabets.end()), alphabets.end());
	int s = alphabets.size();
	vector<int> numbers;
	for (int i = 9; i > 9 - s; i--) { // 최대값을 구하는 문제니까 9부터 알파벳 개수만큼 숫자 고르기
		numbers.push_back(i);
	}

	// 순열 최대값 구하기
	int ans = 0;
	do {
		int tmp = calc(wordArr, alphabets, numbers);
		if (ans < tmp) {
			ans = tmp;
		}
	} while (prev_permutation(numbers.begin(), numbers.end()));

	cout << ans << '\n';
	return 0;
}
