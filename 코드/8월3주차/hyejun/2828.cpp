#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#pragma warning(disable:4996)

using namespace std;

const int mx = 24;
int N, M, J;
int apple[mx];
int ans = INT_MAX;

void go(int curEnd, int dist, int cnt) { // 반복되는 로직: 현재 위치에서 사과를 담을 수 있는지 확인
    if (dist > ans) return;

    if (cnt == J) { // 기저 사례
        ans = min(ans, dist);
        return;
    }

    for (int nextEnd = M; nextEnd <= N; ++nextEnd) {
        if (nextEnd - M + 1 <= apple[cnt] && apple[cnt] <= nextEnd) {
            // 사과 담기 성공
            go(nextEnd, dist + abs(nextEnd - curEnd), cnt + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M >> J;
    for (int i = 0; i < J; ++i) {
        cin >> apple[i];
    }
    go(M, 0, 0);
    cout << ans << '\n';

    return 0;
}
