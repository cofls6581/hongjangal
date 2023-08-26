#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    string s;
    cin>>s;
    string r=s;
    reverse(r.begin(),r.end());

    for(int i=0; i<s.size();++i){
        if(s[i]!=r[i]){
            cout<<0<<'\n';
            return 0;
        }
    }
    cout<<1<<'\n';
    return 0;
}
