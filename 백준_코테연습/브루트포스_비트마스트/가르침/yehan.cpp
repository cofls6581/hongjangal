#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count(int mask, vector <int>& words) {
    int cnt = 0;
    for (int word : words) {
        if ((word & ((1 << 26) - 1 - mask)) == 0) {
            cnt++;
        }
    }
    return cnt;
}

int solve(int idx, int k, int mask, vector<int>& words) {
    if (k < 0) return 0; // 불가능한 경우 
    if (idx == 26) return count(mask, words); // 가능한 경우
        
    int ans = 0;
    int tmp = solve(idx + 1, k - 1, mask | (1 << idx), words); //현재 인덱스 알파벳 포함 
    if (ans < tmp) ans = tmp;
    if (idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a') {
        tmp = solve(idx + 1, k, mask, words); //현재 인덱스 알파벳 포함 X
        if (ans < tmp) ans = tmp;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    // 입력 및 초기화
    int n, k;
    cin >> n >> k;
    vector<int> words(n); // 포함된 알파벳 비트로 저장
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) { // 단어에 알파벳이 있다면 1로 설정
            words[i] |= (1 << (c - 'a'));
        }
    }

    // 문제 풀기, 출력 및 종료
    cout << solve(0, k, 0, words) << '\n';

    return 0;
}
