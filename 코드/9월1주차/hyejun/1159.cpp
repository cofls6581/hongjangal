#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

const int alpha = 26;
const int mx = 30;
int n, cnt[mx], flag;
string s;
vector<char> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        cnt[s[0] - 'a']++;
    }
    for (int i = 0; i < alpha; ++i) {
        if (cnt[i] >= 5) {
            flag = 1;
            v.push_back('a' + i);
        }
    }
    sort(v.begin(), v.end());
    if (!flag) cout << "PREDAJA" << '\n';
    else {
        for (char i : v) {
            cout << i;
        }
    }


    return 0;
}
