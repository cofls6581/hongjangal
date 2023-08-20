#include <bits/stdc++.h>
using namespace std;

int n,m,hour,num;
int a[102][102]={0,};
int visited[102][102]={0,};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector <pair<int,int>>v;

void dfs(int x, int y){
    visited[x][y] = 1;
    if(a[x][y]==1){
        v.push_back({x,y});
        return;
    }

    for(int i=0;i<4;++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m||visited[nx][ny]) continue;
        dfs(nx,ny);
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

     while(true){
        num =0;
        memset(visited,0,sizeof(visited));
        v.clear(); 
        dfs(0,0); 

        for(pair<int, int> b : v){
			num++;
			a[b.first][b.second] = 0;
		}   

        bool flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] != 0) flag = 1;
            }
        }
        hour++;
        if(!flag) break;
    }
    cout<<hour<<"\n" << num << '\n'; 
    return 0;
}
