#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            { // 대문자
                if (s[i] + 13 > 90)
                    s[i] = s[i] + 13 - 26;
                else
                    s[i] = s[i] + 13;
            }
            else
            { // 소문자
                if (s[i] + 13 > 122)
                    s[i] = s[i] + 13 - 26;
                else
                    s[i] = s[i] + 13;
            }
        }
        cout << s[i];
    }

    return 0;
}
