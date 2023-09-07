#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int x,y;
    int tmpN=n;
    while(tmpN--){
        cin>>x>>y;
        pq.push({x,y});
    }

    int ans=0;
    int l,r;
    tie(l,r)=pq.top(); pq.pop();

    for(int i=1; i<n; ++i){
        tie(x,y)=pq.top(); pq.pop();
        if(x>r) {
            ans+=(r-l);
            l=x;
            r=y;
        }
        else if(x<=r&&y>r)
        {
            r=y;
        }
    }
    ans+=(r-l);
    cout<<ans<<'\n';

    return 0;
}
