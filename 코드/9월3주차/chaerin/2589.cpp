#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,m;
char a[52][52];
int  visited[52][52]={0,};
vector <pii> lands;
int ans=0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int bfs(int x, int y){
    int tmp=0;
    visited[x][y]=1; 
    queue <pii> q;
    q.push({x,y});
    while(q.size()){
        tie(x,y)=q.front(); q.pop();
        for(int i=0;i<4;++i){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(visited[nx][ny]||(a[nx][ny]!='L')) continue;
            visited[nx][ny]=visited[x][y]+1;
            q.push({nx,ny});
            tmp=max(tmp,visited[nx][ny]);
        }
    }
    return tmp-1;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>m;
    string s;
    for(int i=0;i<n;++i){
        cin>>s;
        for(int j=0;j<m;++j){
            a[i][j]=s[j];
            if(s[j]=='L') lands.push_back({i,j});
        }
    }
    int x,y;
    for(int i=0;i<lands.size();++i){
        memset(visited,0,sizeof(visited));
        tie(x,y)=lands[i];
        ans=max(ans,bfs(x,y));
    }
    cout<<ans<<'\n';
    return 0;
}
