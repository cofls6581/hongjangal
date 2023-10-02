#include <iostream>
#include <stack>
#include <vector>
// #pragma warning(disable:4996)

using namespace std;

string s, bomb;
int bLen;
stack<char> st;
vector<char> v;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout); 

    cin >> s >> bomb;
    bLen = bomb.size();
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != bomb[bLen - 1]) {
            st.push(s[i]);
        }
        else { // 폭발 문자열의 마지막 문자인 경우
            if (bLen == 1) continue;
            stack<char> st2;
            for (int j = 1; j <= bLen - 1; j++) {
                if (st.size() && st.top() == bomb[bLen - 1 - j]) {
                    st2.push(st.top());
                    st.pop();
                }
                else {
                    while (st2.size()) {
                        st.push(st2.top());
                        st2.pop();
                    }
                    st.push(s[i]);
                    break;
                }
            }
        }
    }
    if (st.empty()) cout << "FRULA";
    else {
        while (st.size()) {
            v.push_back(st.top());
            st.pop();
        }
        for (int i = v.size() - 1; i >= 0; --i) cout << v[i];
    }

    return 0;
}
