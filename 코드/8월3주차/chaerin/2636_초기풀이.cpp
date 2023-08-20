#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[102][102]={0,};
int visited[102][102]={0,};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
queue <pair<int,int>> air;
int cheeseN=0;
stack <pair<int,int>> st;
int num;

void dfs(int x, int y){
    for(int i=0;i<4;++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m||visited[nx][ny]) continue;
        if(a[nx][ny]==1){
            cheeseN--; num++;
            a[nx][ny]=0; air.push({nx,ny});
        } 
        visited[nx][ny]=1; 
        if(!cheeseN) return;
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
                cin>>a[i][j];
                if(a[i][j]==0) air.push({i,j});
                if(a[i][j]==1) cheeseN++;
        }
    }

    int x,y;
    int day=0;
    while(cheeseN){
        int once=air.size();
        num=0;
        day++; 
        while(once--){
            tie(x,y)=air.front(); air.pop();
            visited[x][y]=1;
            dfs(x,y);
        }
        st.push({day,num});
    }
    cout<<st.top().first<<'\n'<<st.top().second<<'\n';
    return 0;
}
