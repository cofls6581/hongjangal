/*
합이 1로 끝나는 경우, 2로 끝나는 경우, 3으로 끝나는 경우로 나눌 수 있음을 이용해서 dp로 풀이함
*/
#include <iostream>
#define MAX 11

using namespace std;

int d[MAX];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        d[1] = 1;
        d[2] = 2;
        d[3] = 4;
        for (int i = 4; i <= n; i++) {
            d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        }
        cout << d[n] << '\n';
    }

    return 0;
}
