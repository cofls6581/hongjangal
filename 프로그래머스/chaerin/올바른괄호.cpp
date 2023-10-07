#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack <char> st;
    if(s.size()==0||(s.size()%2!=0)) return false;
    
    for(int i=0; i<s.size();++i){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{ // ')'
            if(st.empty()) return false;
            st.pop();
        }
    }
    if(!st.empty()) return false;
    return answer;
}
