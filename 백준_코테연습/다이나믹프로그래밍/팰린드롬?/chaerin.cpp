#include <iostream>
#include <cstring>
using namespace std;

int d[2000][2000];
int a[2000];
int n,m;

int dp(int i, int j) {
	if (i == j) return 1; //길이 1
	else if (i + 1 == j) { // 길이 2
		if (a[i] == a[j]) return d[i][j] = 1; //팰린드롬 o
		else return d[i][j] = 0; //팰린드롬 x
	}

	if (d[i][j] >= 0) return d[i][j]; //메모제이션

	if (a[i] != a[j]) return d[i][j] = 0;
	else return d[i][j] = dp(i + 1, j - 1);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i]; }
    cin>>m;
    memset(d,-1,sizeof(d));
    while(m--){
        int i,j;
        cin>>i>>j;
        cout<<dp(i-1,j-1)<<'\n';
    }
    return 0;
}
