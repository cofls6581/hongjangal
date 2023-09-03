#include <iostream>
#include <string>
#include <map>
#pragma warning(disable:4996)

using namespace std;

int t, n, pos;
long long ans;
string s;
map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while (t--) {
        mp.clear();
        ans = 1;
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            pos = s.find(" ");
            mp[s.substr(pos + 1)]++;
        }
        for (auto i : mp) {
            ans *= ((long long)i.second + 1);
        }
        // 아무것도 안 선택하는 경우 제외
        ans--;
        cout << ans << '\n';
    }

    return 0;
}
