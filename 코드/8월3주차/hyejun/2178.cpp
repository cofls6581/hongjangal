#include <iostream>
#include <queue>
#include <tuple>
#pragma warning(disable:4996)

using namespace std;

const int mx = 104;
int a[mx][mx];
int visited[mx][mx];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int n, m;

void bfs(int sy, int sx) {
    // 칸을 셀 때에는 시작 위치와 도착 위치도 포함
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    visited[sy][sx] = 1;

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny<1 || ny>n || nx<1 || nx>m) continue;
            if (visited[ny][nx]) continue;
            if (a[ny][nx] == 1) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    // 가중치가 같은 그래프의 최단거리 -> BFS
    // 문제에 주어진 맵으로 구현 시 O(N * M) -> O(100 * 100)
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 1; j <= m; ++j) {
            a[i][j] = s[j - 1] - '0';
        }
    }

    bfs(1, 1);

    cout << visited[n][m] << '\n';

    return 0;
}
