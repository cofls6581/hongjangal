#include <bits/stdc++.h>
using namespace std;

int n,r,root;
vector<int> a[52];
bool visited[52] = {0,};
int ans=0;

void dfs(int cur) {
    visited[cur]=1;
    if(a[cur].empty()){
        ans++; return;
    } 
    if(a[cur].size()==1&&a[cur].front()==r){
        ans++; return;
    }
    for(int nx: a[cur]){
        if(nx==r) continue;
        if(!visited[nx]) dfs(nx);
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    int parent;
    for(int i=0;i<n;++i){
        cin>>parent;
        if(parent==-1) root=i;
        else a[parent].push_back(i);
    }
    cin>>r;
    if(r == root){
        cout << 0 << '\n';
    }
    else{
        dfs(root);
        cout << ans << '\n';
    }
    return 0;
}
