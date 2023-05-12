#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int visit[9];
int arr[9];
int ant[9];

void solve (int cnt) {
    if(cnt==m) {
        for(int i=0;i<m;++i){
            cout<<ant[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    int tmp = 0;
    for(int i=0;i<m;++i){
        if(!visit[i]&& tmp!= arr[i]){
            visit[i]=1;
            ant[cnt]=arr[i];
            tmp = arr[cnt];
            solve(cnt+1);
            visit[i]=0;
        }
    }

}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    solve(0);
    return 0;
}
