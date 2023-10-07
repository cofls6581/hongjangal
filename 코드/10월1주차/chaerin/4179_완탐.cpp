#include <bits/stdc++.h>
using namespace std;
#define MAX 1002

int r,c;
char arr[MAX][MAX]; // input
int fire[MAX][MAX]; // 불 확산 및 불 확산 시각 저장
int jihoon[MAX][MAX]; 
queue <pair<int,int>> qf,qj;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans=-1;

void bfsFire(){
    int x,y;
    while(!qf.empty()){
        tie(x,y)=qf.front(); qf.pop();
        for(int i=0; i<4; ++i){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=r||ny<0||ny>=c||(fire[nx][ny]!=-1||arr[nx][ny]=='#')) continue;
            fire[nx][ny]=fire[x][y]+1;
            qf.push({nx,ny});
        }
    }
}

void bfsJihoon(){
    int x,y;
    while(!qj.empty()){
        tie(x,y)=qj.front(); qj.pop();
        for(int i=0; i<4; ++i){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=r||ny<0||ny>=c){
                ans=jihoon[x][y]+1;
                return;
            } 
            if((jihoon[nx][ny]!=-1)||arr[nx][ny]=='#') continue;
            if((fire[nx][ny]!=-1)&&fire[nx][ny]<=(jihoon[x][y]+1)) continue;
            jihoon[nx][ny]=jihoon[x][y]+1;
            qj.push({nx,ny});
        }
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>r>>c;
    memset(fire,-1,sizeof(fire));
    memset(jihoon,-1,sizeof(jihoon));
    for(int i=0; i<r; ++i){
        for(int j=0; j<c ;++j){
            cin>>arr[i][j];
            if(arr[i][j]=='J'){
                qj.push({i,j});
                jihoon[i][j]=0;
            }
            else if(arr[i][j]=='F'){
                qf.push({i,j});
                fire[i][j]=0;
            }
        }
    }
    
    bfsFire();
    bfsJihoon();
    if(ans!=-1) cout<<ans<<'\n';
    else cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}
