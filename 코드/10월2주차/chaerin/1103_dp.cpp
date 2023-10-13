#include <bits/stdc++.h>
#define MAX 52
using namespace std;

int n,m;
char arr[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans=0;
bool visited[MAX][MAX];
int dp[MAX][MAX];

bool check(int x, int y){
    if(arr[x][y]=='H') return false;
    if(x<0||x>=n||y<0||y>=m) return false;
    return true;
}

int dfs(int x, int y){
    if(!check(x,y)) return 0;
    if(visited[x][y]){ // 사이클 처리
        cout << -1 << "\n";
        exit(0); 
    }

    int &ans=dp[x][y]; // 메모이제이션
    if(ans) return ans;

    visited[x][y]=1;
    int moveN=arr[x][y]-'0';
    for(int i=0; i<4;++i){
        int nx=x+moveN*dx[i];
        int ny=y+moveN*dy[i];
        ans=max(ans,dfs(nx,ny)+1);
    }
    visited[x][y]=0; // 원복 

    return ans;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    cin>>n>>m;
    string s;
    for(int i=0; i<n; ++i){
        cin>>s;
        for(int j=0; j<m; ++j){
            arr[i][j]=s[j];
        }
    }
    cout<<dfs(0,0)<<'\n';

    return 0;
}
