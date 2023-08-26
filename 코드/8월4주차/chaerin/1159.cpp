#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[151]={0,};

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        cnt[s[0]-'a']++;
    }

    string ans="";
    for(int i=0; i<151;++i){
        if(cnt[i]>=5) ans+=(char)(i+'a');
    }
    if(ans=="") cout<<"PREDAJA\n";
    else cout<<ans<<'\n';

    return 0;
}
