#include <bits/stdc++.h>
using namespace std;

int n,m,j,l,r;
int ans=0;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>m>>j;
    l=1;

    int next;
    while(j--){
        r=l+m-1;
        cin>>next;
        if(l<=next&&next<=r)
            continue;
        else{
            if(next<l){
                ans+=(l-next);
                l=next;
            }
            else{
                ans+=(next-r);
                l+=(next-r);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
