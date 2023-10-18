#include <iostream>
#pragma warning(disable:4996)

using namespace std;

const int mx = 9;
int R, C, K, visited[mx][mx], cnt;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
char a[mx][mx];
string s;

void go(int y, int x) {
    if (visited[y][x] > K) return;
    if (make_pair(y, x) == make_pair(0, C - 1)) {
        if (visited[y][x] == K) cnt++;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || a[ny][nx] == 'T') continue;
        visited[ny][nx] = visited[y][x] + 1;
        go(ny, nx);
        visited[ny][nx] = 0;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> R >> C >> K;
    for (int i = 0; i < R; ++i) {
        cin >> s;
        for (int j = 0; j < C; ++j) {
            a[i][j] = s[j];
        }
    }
    visited[R - 1][0] = 1;
    go(R - 1, 0);
    cout << cnt << '\n';

    return 0;
}
