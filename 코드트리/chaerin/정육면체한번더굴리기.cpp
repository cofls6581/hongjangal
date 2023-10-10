#include <bits/stdc++.h>
using namespace std;
#define MAX 22

int n,m;
int a[MAX][MAX];
bool visited[MAX][MAX];
int ans=0;
int cnt;

pair<int,int> loc={0,0};
int u,r,l; //문제 예시 동일한 방향 주사위 노출 값 (위, 앞, 옆)

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};
int direct=0;

bool inRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void rollDice(){ 
    //direct 맞춰서 u,r,l 업데이트 함수
    int pu=u; int pr=r; int pl=l;
    if(direct==0){
        l=pu;
        u=7-pl;
    }
    else if(direct==1){
        r=pu;
        u=7-pr;
    }
    else if(direct==2){
        u=pl;
        l=7-pu;
    }
    else{
        u=pr;
        r=7-pu;
    }
}

void getScore(int x, int y, int num){ //dfs
    visited[x][y]=1; cnt++;

    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(inRange(nx,ny) && !visited[nx][ny] && a[nx][ny] == num){
            getScore(nx,ny,num);
        }
    }
    
}

pair<int,int> move(int x, int y){
    int newx=x+dx[direct];
    int newy=y+dy[direct];

    if(newx>=n){
        newx=n-2;
        direct=3;
    }
    else if(newx<0){
        newx=1;
        direct=1;
    }
    else if(newy>=n){
        newy=n-2;
        direct=2;
    }
    else if(newy<0){
        newy=1;
        direct=0;
    }

    rollDice();

    return make_pair(newx,newy);
}

int nextDirect(int x, int y) {
    int under=7-u;
    if(under>a[x][y]){ //시계
        direct=(direct + 1) % 4;
    }
    else if(under<a[x][y]){ //반시계
        direct=(direct - 1 + 4) % 4;;
    }
    return direct;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n;++i){
        for(int j=0; j<n; ++j){
            cin>>a[i][j];
        }
    }

    u=1;r=2;l=3;
    while(m--){
        loc=move(loc.first,loc.second);
        cnt=0; memset(visited,0,sizeof(visited));
        getScore(loc.first,loc.second,a[loc.first][loc.second]);
        ans+=cnt*a[loc.first][loc.second];
        direct=nextDirect(loc.first,loc.second);
    }
    cout<<ans<<'\n';

    return 0;
}
