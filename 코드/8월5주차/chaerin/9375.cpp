#include <iostream>
#include <map>
using namespace std;

int t, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> t;
    string a, b;
    while (t--)
    {
        cin >> n;
        map<string, int> m;
        long long ans = 1;
        while (n--)
        {
            cin >> a >> b;
            m[b]++;
        }
        for (auto k : m)
        {
            ans *= (k.second + 1);
        }
        ans -= 1;
        cout << ans << '\n';
    }
    return 0;
}
