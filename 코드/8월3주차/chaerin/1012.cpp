#include <bits/stdc++.h>
using namespace std;

int m,n,t,k;
int arr[52][52]={0,};
int visited[52][52];
int ans=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int x, int y){
    visited[x][y]=1;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(visited[nx][ny]!=0||nx<0||nx>=m||ny<0||ny>=n)
            continue;
        if(arr[nx][ny]==1)
            dfs(nx,ny);
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>t;
    while(t--){
        memset(arr,0,sizeof(arr));
        memset(visited,0,sizeof(visited));
        ans=0;
        cin>>m>>n>>k;
        int x,y;
        while(k--){
            cin>>x>>y;
            arr[x][y]=1;
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(arr[i][j] == 1 && visited[i][j]==0){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
