#include <iostream>
#include <cstring>
using namespace std;

int a[1001];
int d[1001];
int n;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    //로직
    memset(d,-1,sizeof(d));
    d[1]=0;
    for(int i=2;i<=n;++i){
        for(int j=1;j<i;++j){
            if(d[j]!=-1 && i-j<=a[j]){ //이동 가능 조건 체크
                if(d[i]==-1 || d[i]>d[j]+1) { // d[i] 변경 가능 체크 
                    d[i]=d[j]+1;
                }
            }
        }
    }
    //output
    cout<<d[n]<<'\n';
    return 0;
}
