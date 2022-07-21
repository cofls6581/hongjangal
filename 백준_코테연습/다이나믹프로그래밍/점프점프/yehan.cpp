#include <iostream>
#include <cstring>
using namespace std;

int maze[1001];
int dp[1001];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> maze[i];

    // 문제 풀기
    memset(dp, -1, sizeof(dp));
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (dp[j] != -1 && i - j <= maze[j]) {
                if (dp[i] == -1 || dp[i] > dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    //출력 및 종료
    cout << dp[n] << '\n';
    return 0;
}
