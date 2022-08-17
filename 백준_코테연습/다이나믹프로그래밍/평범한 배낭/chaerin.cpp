#include <iostream>
#include <algorithm>
using namespace std;

int d[101][100001];
int w[101];
int v[101];
int n,k;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> w[i] >> v[i];
    }
    //로직
    for (int i=1; i<=n; i++) {
        for (int j = 1; j <= k; j++) {
			d[i][j] = d[i - 1][j]; //i번째 포함 x
			if (j - w[i] >= 0) { //i번째 포함 o
				d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);
			}
		}
    }
    //output
    cout << d[n][k] << '\n';
    return 0;
}
