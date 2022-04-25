#include <iostream>
using namespace std;

int n,m;
int input[500][500];
bool visit[500][500];
int ans=0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void solve(int x, int y, int sum, int cnt){
    //정답인 경우
    if(cnt==4){
        if(ans<sum) 
            ans=sum;
        return;
    }

    //정답 불가능한 경우
    if(x<0||x>=n||y<0||y>=m)
        return;
    if(visit[x][y])
        return;
    
    //다음 케이스 호출
    visit[x][y]=true;
    for(int k=0;k<4;++k){
        solve(x+dx[k],y+dy[k],sum+input[x][y],cnt+1);
    }
    visit[x][y]=false; //dfs 사용시 삭제
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>input[i][j];
        }
    }
    //로직
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            solve(i,j,0,0); //엿모양 제외 
            //엿모양 
            if(j+2<m){
                int tmp=input[i][j]+input[i][j+1]+input[i][j+2]; //세로형
                if(i-1>=0){ //왼쪽 뾰족
                    int tmp2=tmp+input[i-1][j+1];
                    if(ans<tmp2) 
                        ans=tmp2;
                }
                if(i+1<n){ //오른쪽 뾰족
                    int tmp2=tmp+input[i+1][j+1];
                    if(ans<tmp2) 
                        ans=tmp2;
                }
            }
            if(i+2<n){
                int tmp=input[i][j]+input[i+1][j]+input[i+2][j]; //가로형
                if(j+1<m){ //위 뾰족
                    int tmp2=tmp+input[i+1][j+1];
                    if(ans<tmp2) 
                        ans=tmp2;
                }
                if(j-1>=0){ //아래 뾰족
                    int tmp2=tmp+input[i+1][j-1];
                    if(ans<tmp2) 
                        ans=tmp2;
                }
            }
        }
    }
    //output
    cout<<ans<<'\n';
    return 0;
}
