#include <iostream>
#include <stack>
using namespace std;

int n;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    string s;

    while (n--)
    {
        cin >> s;
        stack<char> c;
        c.push(s[0]);
        for (int i = 1; i < s.size(); ++i)
        {
            if (c.size())
            {
                char tmp = c.top();
                if (tmp == s[i])
                {
                    c.pop();
                }
                else
                {
                    c.push(s[i]);
                }
            }
            else
            {
                c.push(s[i]);
            }
        }
        if (c.empty())
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
