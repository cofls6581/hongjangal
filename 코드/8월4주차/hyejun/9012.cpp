#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int t, l, r, flag;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while (t--) {
        l = 0; r = 0; flag = 0;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') l++;
            else r++; // ')'
            if (l == 0 && r > 0) {
                flag = 1;
                break;
            }
            if (l == r) {
                l = 0;
                r = 0;
            }
        }
        if (flag || l != r) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }

    return 0;
}
