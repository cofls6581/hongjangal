#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n;
string s, snum;
vector<string> v;

bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b; // 문자열 길이가 같으면 앞부터 차례대로 아스키코드 비교
    return a.size() < b.size(); // 문자열 길이가 다르면 긴 쪽이 더 큰 숫자
}

void go() {
    // 앞에 있는 0 제거
    while (1) {
        if (snum.size() && snum.front() == '0') snum.erase(snum.begin());
        else break;
    }
    // 숫자가 0000 인 경우 다 제거되므로 0 저장 
    if (snum.size() == 0) snum = "0";
    // 저장
    v.push_back(snum);
    // 초기화
    snum = "";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int tc = 0; tc < n; ++tc) {
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < 'a') snum += s[i];
            else {
                if (snum.size()) go();
            }
        }
        // 마지막이 숫자인 경우
        if (snum.size()) go();
    }

    sort(v.begin(), v.end(), cmp);

    for (auto each : v) {
        cout << each << '\n';
    }

    return 0;
}
