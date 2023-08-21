#include <bits/stdc++.h>
using namespace std;

stack <int> s;
int a[1000002];
int n;
int ans[1000002];

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    memset(ans,-1,sizeof(ans));
    for(int i=0; i<n;++i){
        cin>>a[i];
        while(s.size()&&a[s.top()]<a[i]){
            ans[s.top()]=a[i]; 
            s.pop();
        }
        s.push(i);
    }
    for(int i=0; i<n;++i){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    return 0;
}
