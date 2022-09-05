#include <iostream>
using namespace std;

int n;
long long d[1001];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin >> n;
    //로직
    d[0]=0;
    for(int i=1;i<=n;++i) {
        d[i]=d[i-1]+1;
        for(int j=1;j<=i-2;j++) {
            d[i]=max(d[i],d[i-(j+2)]*(j+1));
        }
    }
    //output
    cout << d[n] << '\n';
    return 0;
}
