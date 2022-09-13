#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int d[4001][4001];
string a,b;
int n,m;
int ans = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin >> a >> b;
    //로직
    n=a.size(); 
    m=b.size();
    a = " " + a;
    b = " " + b;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i]==b[j]) {
                d[i][j]=d[i-1][j-1] + 1;
            }
            else {
                d[i][j] = 0;
            }
        }
    }
    //output
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ans=max(ans,d[i][j]);
        }
    }
    cout << ans << '\n';

    return 0;
}
