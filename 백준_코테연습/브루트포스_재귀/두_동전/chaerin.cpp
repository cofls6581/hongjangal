#include <iostream>
using namespace std;

int n,m;
string input[21];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int solve(int cnt, int x1, int y1, int x2, int y2){
    //정답 안되는 경우 1
    if(cnt==11) 
        return -1;
    //동전 체크
    bool c1=false,c2=false;
    if(x1<0||y1<0||x1>=n||y1>=m)
        c1=true;
    if(x2<0||y2<0||x2>=n||y2>=m)
        c2=true;
    //정답 안되는 경우 2
    if(c1&&c2) 
        return -1;
    //정답인 경우
    if(c1||c2) 
        return cnt;
    //다음 호출 필요
    int ans=-1;
    for(int k=0;k<4;++k){
        int nx1=x1+dx[k];
        int ny1=y1+dy[k];
        int nx2=x2+dx[k];
        int ny2=y2+dy[k];
        if(0<=nx1&&nx1<n&&0<=ny1&&ny1<m&&input[nx1][ny1]=='#'){
            nx1=x1;
            ny1=y1;
        }
        if(0<=nx2&&nx2<n&&0<=ny2&&ny2<m&&input[nx2][ny2]=='#'){
            nx2=x2;
            ny2=y2;
        }
        int tmp=solve(cnt+1,nx1,ny1,nx2,ny2);
        if(tmp==-1) 
            continue;
        if(ans==-1 || ans > tmp)
            ans=tmp;
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n>>m;
    int x1,y1,x2,y2;
    x1=x2=y1=y2=-1;
    for(int i=0;i<n;++i){
        cin>>input[i];
        for(int j=0;j<m;++j){
            if(input[i][j]=='o'){
                if(x1==-1){
                    x1=i; y1=j;
                }
                else{
                    x2=i; y2=j;
                }
                input[i][j]='.';
            }
        }
    }
    
    //output
    cout<<solve(0,x1,y1,x2,y2)<<'\n';
    return 0;
}
