#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

string s, ans;
int cnt[100], flag;
char mid;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> s;
    for (char i : s) cnt[i]++;
    for (int i = 'Z'; i >= 'A'; --i) {
        if (cnt[i]) {
            if (cnt[i] & 1) { // 홀수개
                flag++;
                mid = (char)i;
                cnt[i]--;
            }
            if (flag == 2) break;
            for (int j = 0; j < cnt[i]; j += 2) {
                ans = (char)i + ans; // 앞
                ans += (char)i; // 뒤

            }
        }
    }
    if (mid) ans.insert(ans.begin() + ans.size() / 2, mid);
    if (flag == 2) cout << "I'm Sorry Hansoo" << '\n';
    else cout << ans << '\n';

    return 0;
}
