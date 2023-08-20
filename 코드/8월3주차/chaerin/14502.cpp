#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[70];
bool visited[70];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<pair<int, int>> virus;
int ans=0;

void dfs(int x, int y) {
    visited[x*m+y]=1;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        if(visited[(nx*m)+ny]||arr[(nx*m)+ny]==1) continue;
        dfs(nx,ny);
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n*m; ++i) {
        cin>>arr[i];
        if(arr[i] == 2) virus.push_back({i/m, i-(m*(i/m))});
    }

    int ans=0;
    for(int i = 0; i < n*m; ++i){ 
        if(arr[i]!=0) continue;
        for(int j = i + 1; j < n*m; ++j){
            if(arr[j]!=0) continue;
            for(int k = j + 1; k < n*m; ++k){
                if(arr[k]!=0) continue;
                //가벽 세우기
                arr[i]=arr[j]=arr[k]=1;
                //바이러스 전파
                memset(visited,0,sizeof(visited));
                for(pair<int, int> v : virus) {
                    dfs(v.first,v.second);
                }
                //안전 영역 계산
                int safe=0;
                for(int u=0; u<n*m; ++u) {
                    if(arr[u] == 0 && !visited[u]) safe++;
                }
                ans=max(ans,safe);
                //가벽 원복
                arr[i]=arr[j]=arr[k]=0;
            } 
        }
    }

    cout<<ans<<'\n';

    return 0;
}
