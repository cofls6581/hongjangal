#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int a[1001][1001]; //input 1이면 벽 0이면 빈칸
int d[1001][1001][2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    //로직
    queue<tuple<int,int,int>> q;
    d[0][0][0]=1;
    q.push(make_tuple(0,0,0));
    while(!q.empty()){
        int x,y,z;
        tie(x,y,z)=q.front(); 
        q.pop();
        for(int k=0;k<4;++k){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx<0||nx>=n||ny<0||ny>=m)
                continue;
            if(a[nx][ny]==0&&d[nx][ny][z]==0){
                d[nx][ny][z]=d[x][y][z]+1;
                q.push(make_tuple(nx,ny,z));
            }
            if(z==0&&a[nx][ny]==1&&d[nx][ny][z+1]==0){ //벽 부시고 갈 경우
                d[nx][ny][z+1]=d[x][y][z]+1;
                q.push(make_tuple(nx,ny,z+1));
            }
        }
    }
    //output
    if(d[n-1][m-1][0]!=0&&d[n-1][m-1][1]!=0){
        cout<<min(d[n-1][m-1][0],d[n-1][m-1][1])<<'\n';
    }
    else if(d[n-1][m-1][0]!=0){
        cout<<d[n-1][m-1][0]<<'\n';
    }
    else if(d[n-1][m-1][1]!=0){
        cout<<d[n-1][m-1][1]<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }
    return 0;
}
