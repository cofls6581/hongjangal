#include <iostream>
#include <vector>
using namespace std;

#define MAX 15002

int n,m;
int a[MAX];

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>a[i];
    int ans=0;
    for(int i=0; i<n;++i){
        for(int j=i+1; j<n;++j){
            if((a[i]+a[j])==m) ans++;
        }

    }
    cout<<ans<<'\n';
    return 0;
}
