#include <bits/stdc++.h>
using namespace std;
#define MAX 10002

int n,m;
vector <int> a[MAX];
bool visited[MAX]={0,};
int ans=0;

int dfs(int cur) {
    int cnt=1;
    visited[cur]=1;
    for(int nx : a[cur]){
        if(visited[nx]) continue;
        cnt+=dfs(nx);
    }
    return cnt;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>m;
    int x,y;
    while(m--){
        cin>>x>>y;
        a[y].push_back(x);
    }
    int mark[MAX];
    for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		mark[i] = dfs(i); 
		ans = max(mark[i], ans);
	} 
    for (int i = 1; i <= n; i++) if (ans == mark[i]) cout << i << " "; 
    cout<<'\n';
    return 0;
}
