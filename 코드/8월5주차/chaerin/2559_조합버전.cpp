#include <bits/stdc++.h>
using namespace std;

#define MAX 100002

int a[MAX];
int n,k;
int ans=-1;

void func(int start, vector <int> v){
    if(v.size()==k){
        int tmp=0;
        for(int i=0; i<k;++i){
            tmp+=a[v[i]];
        }
        if(tmp>ans) ans=tmp;
        return;
    }

    for(int i=start+1; i<n;++i){
        v.push_back(i);
        func(i,v);
        v.pop_back();
    }
    return;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>k;
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    vector<int> v;
    func(-1,v);
    cout<<ans<<'\n';
    return 0;
}
