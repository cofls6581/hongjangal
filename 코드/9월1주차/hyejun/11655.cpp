#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;

const int alpha = 26;
string s;

char calc(char c) {
    return (c + 13) % 26;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    getline(cin, s);
    for (int i = 0; i < s.length(); ++i) {
        if (('A' <= s[i]) && (s[i] < 'A' + alpha)) s[i] = 'A' + calc(s[i] - 'A');
        else if (('a' <= s[i]) && (s[i] < 'a' + alpha)) s[i] = 'a' + calc(s[i] - 'a');
    }
    cout << s << '\n';

    return 0;
}
