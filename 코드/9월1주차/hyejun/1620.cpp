#include <iostream>
#include <map>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int n, m;
map<string, int> smp;
map<int, string> imp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    string s;
    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        smp[s] = i;
        imp[i] = s;
    }
    for (int i = 0; i < m; ++i) {
        cin >> s;
        if (s[0] < 'A') cout << imp[stoi(s)] << '\n';
        else cout << smp[s] << '\n';
    }

    return 0;
}
