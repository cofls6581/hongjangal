#include <iostream>
using namespace std;

long long d[51];
long long p[51];
int n;
long long xx;

long long func(int n, long long x){
    
    if (n==0){ //패티한장만
        if(x==0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (x==1){ //햄버거번만
        return 0;
    }
    else if (x<=1+d[n-1]){
        return func(n-1,x-1);
    }
    else if (x==2+d[n-1]){ 
        return p[n-1]+1;
    }
    else if (x<=1 + d[n - 1] + 1 + d[n - 1]) {
        return p[n-1]+1+func(n-1,x-1-d[n-1]-1);
    }
    else {
        return p[n-1]+1+p[n-1];
    }
    
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    //input
    cin>>n>>xx;
    d[0]=1; p[0]=1;
    
    //logic
    for (int i=1; i<=n; ++i) {
        d[i]=3+d[i - 1] * 2;
        p[i]=p[i - 1] * 2 +1;
    }
    //output
    cout << func(n,xx)<<'\n';
    return 0;
}
