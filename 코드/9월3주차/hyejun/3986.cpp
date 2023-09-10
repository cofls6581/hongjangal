#include <iostream>
#include <stack>
#pragma warning(disable:4996)

using namespace std;

int n, ans;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        stack<int> st;
        cin >> s;
        for (char a : s) {
            if (st.size() && st.top() == a) st.pop();
            else st.push(a);
        }
        if (st.empty()) ans++;
    }
    cout << ans << '\n';

    return 0;
}
