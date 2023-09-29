#include <iostream>
#include <cstring>
#include <algorithm>
// #pragma warning(disable:4996)

using namespace std;

const int mx = 16;
const int INF = 1e9;
int n;
int cost[mx][mx], dp[mx][1 << mx]; // dp[현재 도시][현재 방문 상태]

int tsp(int here, int visited) {
    // *** 기저 사례 ***
    if (visited == (1 << n) - 1) { // 모든 도시 방문했을때
        return cost[here][0] ? cost[here][0] : INF; // 여기서 리턴된 값이 이 경로의 비용에 더해짐! (시작도시로 되돌아가는 비용을 리턴)
    }

    // *** 메모이제이션 ***
    int& ret = dp[here][visited];
    if (ret != -1) return ret;

    // *** 로직 (최대값은 최소값부터, 최소값은 최대값부터) ***
    ret = INF;
    for (int i = 0; i < n; ++i) {
        if (cost[here][i] == 0) continue;
        if (visited & (1 << i)) continue; // 이미 방문한 경우
        ret = min(ret, tsp(i, visited | (1 << i)) + cost[here][i]);
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }
    // 초기화 (절대 가질수 없는 값으로)
    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1) << '\n'; // 같은 경로라면, 해당 경로 내의 어떤 도시에서 출발하든 같은 비용을 가지기 때문에 0번째 도시를 출발도시로 해도 됨 -> 0번째 비트 방문 처리

    return 0;
}
