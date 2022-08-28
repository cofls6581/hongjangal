#include <iostream>
using namespace std;

int n,k;
int input[101];
int d[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n>>k;
    for(int i=1; i<=n; ++i){
        cin>>input[i];
    }
    //로직
    d[0]=1; //아무 동전 선택안했을 경우 1
    for(int i=1;i<=n;++i){ 
        for(int j=0;j<=k;++j){
            if(j-input[i]>=0){
                d[j]+=d[j-input[i]];
            }
        }
    }
    //output
    cout<<d[k]<<'\n';
    return 0;
}
