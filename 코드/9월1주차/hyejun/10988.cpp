#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

string s, cp;
int ans = 1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s;
    cp = s;
    reverse(cp.begin(), cp.end());
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != cp[i]) {
            ans = 0;
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}
