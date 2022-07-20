#include <iostream>
using namespace std;

int a[1001][1001];
int d[1001][1001];
int n,m;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin>>a[i][j];
        }
    }
    //로직
     for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            d[i][j] = max(d[i-1][j],d[i][j-1])+a[i][j];
        }
    }
    //output
    cout<<d[n][m]<<'\n';
    return 0;
}
