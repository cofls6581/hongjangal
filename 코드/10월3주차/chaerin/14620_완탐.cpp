#include <bits/stdc++.h>
using namespace std;

int n;
int arr[12][12];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int visited[12][12];
int ans=1e9;

bool check(int x, int y){
    if(x<0||x>=n||y<0||y>=n) return false;
    if(visited[x][y]) return false;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=n) return false;
        if(visited[nx][ny]) return false;
    }
    return true;
}

int put(int x, int y){
    int tmp=0;
    visited[x][y]=1;
    tmp+=arr[x][y];
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        visited[nx][ny]=1;
        tmp+=arr[nx][ny];
    }
    return tmp;
}

void recover(int x, int y){
    visited[x][y]=0;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        visited[nx][ny]=0;
    }
}

void func(int cnt, int tmpAns){
    if(cnt==3){
        ans=min(ans,tmpAns);
        return;
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n ;++j){
            if(check(i,j)){
                func(cnt+1,tmpAns+put(i,j));
                recover(i,j);//원복
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>arr[i][j];
        }
    }
    func(0,0);
    cout<<ans<<'\n';
    
    return 0;
}
