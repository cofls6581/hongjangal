#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[9];
int ans[9];

void solve (int k) {
    if(k==m) {
        for(int i=0;i<m;++i){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=0;i<n;++i){
        ans[k]=arr[i];
        solve(k+1);
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    cin>>n>>m;

    int idx = 0;
    bool chk[10002];

    for(int i=0; i<n; ++i){
        cin>>arr[idx];
        if(chk[arr[idx]]) continue;
        chk[arr[idx]] = true; 
        idx++;
    }

    n=idx;
    sort(arr, arr+n);
    solve(0);
    return 0;
}
