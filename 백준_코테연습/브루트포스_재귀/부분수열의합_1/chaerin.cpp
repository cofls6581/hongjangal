#include <iostream>
using namespace std;
int N,K;
int ans=0;
int arr[20];

void solve(int index, int sum){
    //정답 케이스
    if(sum==K && index==N){
        ans++;
    }
    //정답 도출 불가능한 케이스
    if(N==index) return;
    //다음 호출 필요 케이스
    //현재 인덱스 포함 o
    solve(index+1,sum+arr[index]);
    //현재 인덱스 포함 x
    solve(index+1,sum);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin >> N >> K;
    for(int i=0;i<N;++i){
        cin >> arr[i];
    }
    solve(0,0);
    if(K==0) ans--;
    cout << ans << '\n';
    return 0;
}
