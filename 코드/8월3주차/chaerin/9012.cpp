#include <bits/stdc++.h>
using namespace std;

int t;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>t;

    string s;
    bool isYes;
    while(t--){
        cin>>s;
        stack <int> st;
        isYes=true;
        for(int i=0; i<s.size();++i){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    isYes=false;
                    break;
                }else{
                    st.pop();
                }
            }
        }
        if(!st.empty()){
            isYes=false;
        }
        if(isYes){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
    }

    return 0;
}
