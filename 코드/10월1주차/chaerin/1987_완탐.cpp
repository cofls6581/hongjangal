#include <bits/stdc++.h>
using namespace std;

int r,c;
char arr[22][22];
int ans=0;
int res=0;
int visited[22][22];
bool alpha[27];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int x, int y){
    ans++;
    res=max(res,ans);
    alpha[arr[x][y]-'A']=true;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=r||ny<0||ny>=c) continue;
        if(visited[nx][ny]!=0) continue;
        if(alpha[arr[nx][ny]-'A']) continue;
        dfs(nx,ny);
        visited[nx][ny]=false;
        alpha[arr[nx][ny]-'A']=false;
        ans--;
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>r>>c;
    string s;
    for(int i=0; i<r; ++i){
        cin>>s;
        for(int j=0; j<c; ++j){
            arr[i][j]=s[j];
        }
    }
    visited[0][0]=1;
    dfs(0,0);
    cout<<res<<'\n';
    return 0;
}
