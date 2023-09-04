#include <iostream>
using namespace std;

int a,b,c;
long long ans;

long long func(int a, int b){
    if(b==1) return a%c;
    long long tmp = func(a,b/2);
    tmp = (tmp * tmp) %c;
    if(b%2) tmp=(tmp*a)%c;
    return tmp; 
}

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>a>>b>>c;
    ans=func(a,b);
    cout<<ans<<'\n';
    return 0;
}
