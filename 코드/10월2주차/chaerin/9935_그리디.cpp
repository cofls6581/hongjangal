#include <bits/stdc++.h>
using namespace std;

string s, explosion;
stack <char> st;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>s>>explosion;
    
    for(int i=0; i<s.size();++i){
        st.push(s[i]);
        if(st.size()>=explosion.size()&&st.top()==explosion[explosion.size()-1]){
            string tmp;
            for(int j=0; j<explosion.size();++j){
                tmp+=st.top(); st.pop();
            }
            reverse(tmp.begin(),tmp.end());
            if(tmp!=explosion){
                for(char i: tmp){
                    st.push(i);
                }
            }
        }
    }

    if(st.empty()) cout<<"FRULA"<<'\n';
    else{
        string ans="";
        while(!st.empty()){
            ans+=st.top(); st.pop();
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<'\n';
    }
    return 0;
}
