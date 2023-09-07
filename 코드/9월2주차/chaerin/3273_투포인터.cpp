#include <bits/stdc++.h>
using namespace std;

int n,x;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    cin>>n;
    vector<int> v;

    int tmp,tmpN=n;
    while(tmpN--){
        cin>>tmp;
        v.push_back(tmp);
    }
    cin>>x;

    sort(v.begin(),v.end());
    int ans=0;
    int l=0, r=n-1;
    while(l<r){
        if(v[l]+v[r]==x){
            ans++;
            r--; l++;
        }
        else if(v[l]+v[r]>x) r--;
        else if(v[l]+v[r]<x) l++;
    }

    cout<<ans<<'\n';

    return 0;
}
