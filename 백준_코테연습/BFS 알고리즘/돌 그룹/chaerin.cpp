#include <iostream>
using namespace std;

bool visit[1501][1501];
int x,y,z;
int sum;

void func(int x, int y){
    if(visit[x][y]) return;
    visit[x][y]=true;
    int a[3]={x,y,sum-x-y};
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(a[i]<a[j]){
                int b[3]={x,y,sum-x-y};
                b[i]+=a[i];
                b[j]-=a[i];
                func(b[0],b[1]);
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>x>>y>>z;
    sum=x+y+z;
    //로직
    if(sum%3!=0){
        cout<<0<<'\n';
        return 0;
    }
    func(x,y);
    //output
    if(visit[sum/3][sum/3]){
        cout<<1<<'\n';}
    else{
        cout<<0<<'\n';}
    return 0;
}
