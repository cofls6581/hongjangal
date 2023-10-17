#include <bits/stdc++.h>
using namespace std;

int n;
int arrive, check;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; ++i){
        cin>>arrive>>check;
        v.push_back({arrive,check});
    }
    sort(v.begin(),v.end());
    int cur=0;
    for(int i=0; i<n;++i){
        cur=max(v[i].first,cur);
        cur+=v[i].second;
    }
    cout<<cur<<'\n';
    return 0;
}
