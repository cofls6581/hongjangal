#include <bits/stdc++.h>
using namespace std;

int t;
int m,n,k;
int arr[52][52];
int visited[52][52];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int x, int y){
    visited[x][y]=1;
    for(int i=0; i<4 ;++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=m||ny<0||ny>=n) continue;
        if(visited[nx][ny]||arr[nx][ny]==0) continue;
        dfs(nx,ny);
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>m>>n>>k;
        int ans=0;
        memset(arr,0,sizeof(arr));
        memset(visited,0,sizeof(visited));
        int a,b;
        while(k--){
            cin>>a>>b;
            arr[a][b]=1;
        }
        for(int i=0; i<m;++i){
            for(int j=0; j<n; ++j){
                if(arr[i][j]==1&&!visited[i][j]){
                    dfs(i,j); ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
