#include <iostream>
using namespace std;

int a,b,c;
int cost[102]={0,};

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>a>>b>>c;
    int x,y;
    for(int i=0; i<3; ++i){
        cin>>x>>y;
        for(int j=x;j<y;++j)
            cost[j]++;
    }

    int ans=0;
    for(int i=1; i<101; ++i){
        if(cost[i]==1){
            ans+=a;
        }
        else if(cost[i]==2){
            ans+=(b*2);
        }
        else if(cost[i]==3){
            ans+=(c*3);
        }
    }
    cout<<ans<<'\n';
   return 0; 
}
