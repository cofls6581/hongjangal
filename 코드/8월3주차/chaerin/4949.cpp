#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    while(true){
        string s;
        getline(cin,s);  
        if(s == ".") break;

        stack<int> st;
        bool isYes = true;
        for(int i = 0; i < s.length(); ++i){ 
            if(s[i] == '(') st.push(s[i]);
            if(s[i] == '[') st.push(s[i]); 

            if(s[i] == ')'){ 
                if(st.empty() || st.top() == '['){
                    isYes = false; 
                    break; 
                }else{
                    st.pop();
                }
            }
            if(s[i] == ']'){
                if(st.empty() || st.top() == '('){
                    isYes = false; 
                    break; 
                }else{
                    st.pop();
                }
            } 
        }  
        if(!st.empty()) isYes=false;
        if(isYes) cout<<"yes\n";
        else cout<<"no\n";
    }

    return 0;
}
