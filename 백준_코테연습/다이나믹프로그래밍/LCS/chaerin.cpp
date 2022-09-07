#include <iostream>
using namespace std;

int d[1001][1001];
string a,b;
int n,m;

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
                d[i][j]=max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    //output
    cout << d[n][m] << '\n';
    return 0;
}
