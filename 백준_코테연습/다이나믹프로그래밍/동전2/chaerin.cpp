#include <iostream>
#include <cstring>
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
    memset(d,-1,sizeof(d));
    //로직
    d[0]=0; //아무 동전 선택안했을 경우 0
    for(int i=1;i<=n;++i){ 
        for(int j=0;j<=k;++j){
            if(j-input[i]>=0&&d[j-input[i]]!=-1) {
                if(d[j]==-1||d[j]>(d[j-input[i]]+1)){
                    d[j]=d[j-input[i]]+1;
                }            
            }
        }
    }
    //output
    cout<<d[k]<<'\n';
    return 0;
}
