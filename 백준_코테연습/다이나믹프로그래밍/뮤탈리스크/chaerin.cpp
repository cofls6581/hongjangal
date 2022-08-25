#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int d[61][61][61];
int n;
int scv[3] = {0,0,0};
vector<int> p = {1, 3, 9};

int dp(int i, int j, int k) {
    //파괴됐을 경우 음수 대신 0으로 세팅
    if (i < 0) return dp(0, j, k);
    if (j < 0) return dp(i, 0, k);
    if (k < 0) return dp(i, j, 0);

    if (i == 0 && j == 0 && k == 0) return 0; //모두 파괴

    int &ans = d[i][j][k];
    if (ans != -1) return ans;

    ans = 10000000;
    do {
        if (ans > dp(i-p[0], j-p[1], k-p[2])) {
            ans = dp(i-p[0], j-p[1], k-p[2]);
        }
    } while(next_permutation(p.begin(), p.end()));
    ans += 1;

    return ans;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> scv[i];
    }
    //로직
    memset(d,-1,sizeof(d));
    cout << dp(scv[0], scv[1], scv[2]) << '\n';

    return 0;
}
