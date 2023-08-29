#include <iostream>
#include <stack>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

const int mx = 1000004;
int n, a[mx], nge[mx];
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    memset(nge, -1, sizeof(nge));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        while (st.size() && a[st.top()] < a[i]) {
            nge[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; ++i) cout << nge[i] << ' ';

    return 0;
}
