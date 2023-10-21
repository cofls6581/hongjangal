#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[100002];

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n>>k;
    int tmp;
    for(int i=1; i<=n;++i){ //누적합
        cin>>tmp;
        a[i]=a[i-1]+tmp;
    }

    int ans=-1e9;
    for(int i=k;i<=n;++i){ //k일 합 계산
        ans=max(ans,a[i]-a[i-k]);
    }

    cout<<ans<<'\n';
    
    return 0;
}
