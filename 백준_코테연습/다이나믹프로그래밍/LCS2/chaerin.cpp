#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int d[1001][1001];
int v[1001][1001];
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
                v[i][j] = 1;
            }
            else {
                if (d[i-1][j] < d[i][j-1]) {
                    d[i][j] = d[i][j-1];
                    v[i][j] = 2;
                } 
                else {
                    d[i][j] = d[i-1][j];
                    v[i][j] = 3;
                }

            }
        }
    }
    //output
    cout << d[n][m] << '\n';
    string ans = "";
    while (n > 0 && m > 0) {
        if (v[n][m] == 1) {
            ans += a[n];
            n--; m--;
        } 
        else if (v[n][m] == 2) {
            m--;
        } 
        else {
            n--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}
