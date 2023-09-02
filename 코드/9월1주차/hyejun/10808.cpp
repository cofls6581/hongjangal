#include <iostream>
#pragma warning(disable:4996)

using namespace std;

const int mx = 30;
string s;
int cnt[mx];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        cout << cnt[i] << ' ';
    }

    return 0;
}
