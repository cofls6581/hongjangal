#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    stack<int> st;
    for(int i=0; i<s.size(); ++i) {
        if(s[i]=='(') st.push(s[i]);
        else {
            if(st.size() && st.top()=='(') st.pop();
            else return false;
        }
    }
    if(st.empty()) return true;
    else return false;
}
