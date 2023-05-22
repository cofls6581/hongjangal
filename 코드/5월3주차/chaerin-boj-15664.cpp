#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[9];
int ans[9];

void solve (int k, int cnt) {
    if(k==m) {
        for(int i=0;i<m;++i){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    int tmp = 0;
    for(int i=cnt;i<n;++i){
        if(tmp!= arr[i]){
            ans[k]=arr[i];
            tmp = ans[k];
            solve(k+1,i+1);
        }
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    solve(0,0);
    return 0;
}
