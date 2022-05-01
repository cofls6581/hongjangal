//백트래킹
#include <iostream>
using namespace std;

int n;
bool arr[15][15];
bool col[15];
bool dig1[31];
bool dig2[31];

bool check(int row, int i){
    //열 확인
    if (col[i]) 
        return false;
    //대각선 1 확인
    if (dig1[row+i]) 
        return false;
    //대각선 2 확인
    if (dig2[n+row-i]) 
        return false;

    return true;
}

int solve(int row){
    //정답인 경우
    if(row==n)
        return 1;
    //다음 호출
    int ans=0;
    for(int i=0;i<n;++i){
        if(check(row,i)){//퀸을 놓을 수 있는지 확인
            //퀸을 해당 자리에 둘 수 있다면
            col[i]=true;
            dig1[row+i]=true;
            dig2[n+row-i]=true;
            arr[row][i]=true;

            ans+=solve(row+1);
            //복원
            col[i]=false;
            dig1[row+i]=false;
            dig2[n+row-i]=false;
            arr[row][i]=false;
            
        }
    }
    return ans;
}


int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n;
    //로직+output 
    cout<<solve(0)<<'\n';
    return 0;
}
