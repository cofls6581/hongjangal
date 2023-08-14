/*
이동 최단 경로 -> bfs로 풀자
최대 크기 100*100이니까 시간 제한 1초 문제 x 
붙어서 입력 -> string으로 받아서 처리
인접한 칸 이동 -> dx, dy 
*/
#include <bits/stdc++.h>
using namespace std;

int N,M;
int arr[102][102];
int visited[102][102]={0,};
string s;
int a,b;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int x, int y){
    visited[x][y]=1;
    queue<pair<int,int> > q;
    q.push({x,y});
    while(q.size()){
        tie(a,b)=q.front();
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = a + dx[i]; 
            int ny = b + dy[i]; 
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 0) 
                continue; 
            if(visited[nx][ny]) 
                continue;
            visited[nx][ny] = visited[a][b] + 1; 
            q.push({nx, ny});
        }
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>N>>M;
    for (int i=0; i<N; ++i){
        cin>>s;
        for(int j=0; j<M; ++j){
            arr[i][j]=s[j]-'0';
        }
    }
    bfs(0,0);
    cout<<visited[N-1][M-1]<<'\n';
    return 0;
}
