#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
   
    while(cin>>n){
        ll tmp=1; int ans=1;
        while(1){
            if(tmp%n==0){
                cout<<ans<<'\n';
                break;
            }
            else{
                tmp=tmp*10+1;
                tmp%=n;
                ans++;                
            }

        }
    }
    
    return 0;
}
