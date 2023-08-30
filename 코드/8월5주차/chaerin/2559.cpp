#include <bits/stdc++.h>
using namespace std;

#define MAX 100002

int n,k;
int psum[MAX];

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n>>k;
    int tmp;
    for(int i=1;i<=n;++i){
        cin>>tmp;
        psum[i]=psum[i-1]+tmp;
    }

    int ans=-100000000;
    for(int i=k;i<=n;++i){
        ans = max(ans,psum[i]-psum[i-k]);
    }
    cout<<ans<<'\n';

    return 0;
}
