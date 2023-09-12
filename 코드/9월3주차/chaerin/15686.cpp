#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef pair<int,int> pii;

int n,m;
int a[52][52];
vector <pii> chicken;
vector <pii> home;
vector <pii> v;
int ans=INT_MAX;

int check(){
    int tmp=0;
    for(pii h: home){
        int cur=INT_MAX;
        for(pii vv: v){
            int dist=abs(h.first-vv.first)+abs(h.second-vv.second);
            cur=min(cur,dist);
        }
        tmp+=cur;
    }
    return tmp;
}

void func(int idx){
    if(v.size()==m){
        ans=min(ans,check());
        return;
    }
    for(int i=idx;i<chicken.size();++i){
        v.push_back(chicken[i]);
        func(i+1);
        v.pop_back();
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>m;
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>a[i][j];
            if(a[i][j]==2) chicken.push_back({i,j});
            else if(a[i][j]==1) home.push_back({i,j});
        }
    }
    func(0);
    cout<<ans<<'\n';
    return 0;
}
