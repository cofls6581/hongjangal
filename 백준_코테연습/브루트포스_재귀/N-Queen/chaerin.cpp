#include <iostream>
using namespace std;

int n;
int ans=0;
bool arr[15][15]={false};

bool check(int row, int col){
    //열 확인
    for(int i=0;i<row;++i){
        if(arr[i][col])
            return false;
    }
    //대각선 1 확인
    int x=row-1;
    int y=col-1;
    while(x>=0&&y>=0){
        if(arr[x][y])
            return false;
        x-=1;
        y-=1;
    }
    //대각선 2 확인
    x=row-1;
    y=col+1;
    while(x>=0&&y<n){
        if(arr[x][y])
            return false;
        x-=1;
        y+=1;
    }

    return true;
}

void solve(int row){
    //정답인 경우
    if(row==n){
        ans+=1;
        return;
    }
    //다음 호출
    for(int i=0;i<n;++i){
        arr[row][i]=true;
        if(check(row,i))
            solve(row+1);
        arr[row][i]=false;
    }
}


int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n;
    //로직
    solve(0);
    //output 출력
    cout<<ans<<'\n';

    return 0;
}
