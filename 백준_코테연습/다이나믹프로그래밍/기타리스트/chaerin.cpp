#include <iostream>
using namespace std;

int v[52];
int d[52][1001]={0,};
int n,s,m;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n>>s>>m;
    for(int i=1; i<=n;++i)
        cin>>v[i];
    //로직
    d[0][s]=1; //초기값
    for (int i=1; i<=n; i++) {
        for (int j = 0; j <=m; j++) {
            if (d[i - 1][j] == 1) { //이전 곡 j 볼륨 연주 가능할 때
				if (j + v[i] <= m) {
                    d[i][j + v[i]] = 1; }
				if (j - v[i] >= 0) {
                    d[i][j - v[i]] = 1; } 
			}
		}
    }
    //output
    int ans=-1;
    for (int i = m; i >= 0; i--) {
		if (d[n][i] == 1) {
            ans=i;
            break;
		}
	}
    cout << ans << '\n';
    return 0;
}
