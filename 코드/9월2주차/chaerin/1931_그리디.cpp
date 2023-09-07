#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);

    vector<pair<int,int>> v;
    cin>>n;
    int from,to;
    while(n--){
        cin>>from>>to;
        v.push_back({to,from});
    }
    sort(v.begin(),v.end());
    int ans=0;
    int finish=0;
    for(auto k: v){
        if(finish<=k.second){
            finish=k.first;
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
