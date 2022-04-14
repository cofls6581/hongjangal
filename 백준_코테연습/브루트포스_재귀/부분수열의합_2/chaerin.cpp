#include <iostream>
using namespace std;
int N;
bool c[20*100000];
int arr[20];

void solve(int index, int sum){
    //정답 케이스
    if(index==N){
        c[sum]=true;
        return;
    }
    //다음 호출 필요 케이스
    //현재 인덱스 포함 o
    solve(index+1,sum+arr[index]);
    //현재 인덱스 포함 x
    solve(index+1,sum);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin >> N ;
    for(int i=0;i<N;++i){
        cin >> arr[i];
    }
    solve(0,0);
    for(int i=1;;i++){
        if(!c[i]){
            cout<<i<<'\n';
            break;
        }
    }
    return 0;
}
