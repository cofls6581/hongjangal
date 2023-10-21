#include <bits/stdc++.h>
using namespace std;

int n;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n;
    int arrive,time;
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0; i<n;++i){
        cin>>arrive>>time;
        pq.push({arrive,time});
    }

    int ans=0;
    int x,y;
    for(int i=0; i<n;++i){
        tie(x,y)=pq.top(); pq.pop();
        ans=max(ans,x);
        ans+=y;
    }
    cout<<ans<<'\n';
    
    return 0;
}
