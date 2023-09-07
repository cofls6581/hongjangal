#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

int n,k;

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n>>k;
    int m,v;
    vector<pair<int,int>> j;
    int tmpN=n;
    while(tmpN--){
        cin>>m>>v;
        j.push_back({m,v});
    }
    sort(j.begin(),j.end());

    int c;
    vector<int> bag;
    int tempK=k;
    while(tempK--){
        cin>>c;
        bag.push_back(c);
    }
    sort(bag.begin(),bag.end());

    int idx=0;
    ll ans=0;
    priority_queue <int> pq;
    for(int i=0; i<k; ++i){
        while(idx<n&&j[idx].first<=bag[i]){
            pq.push(j[idx++].second);
        }
        if(pq.size()){
            ans+=pq.top();
            pq.pop();
        }
    }

    cout<<ans<<'\n';

    return 0;
}
