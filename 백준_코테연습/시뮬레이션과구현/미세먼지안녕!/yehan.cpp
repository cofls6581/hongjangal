#include <iostream>
#include <algorithm>
using namespace std;

int finedust[50][50];
int diffusion[50][50];
int n, m, t;
int x, y;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };

void airPurifier(int sx, int sy, int z) {
    int prev = 0;
    int x = sx;
    int y = sy + 1;
    int k = 0;
    while (true) {
        if (x == sx && y == sy) break;
        swap(prev, finedust[x][y]);
        x += dx[k];
        y += dy[k];
        if (x < 0 || y < 0 || x >= n || y >= m) {
            x -= dx[k];
            y -= dy[k];
            k += z;
            k %= 4;
            x += dx[k];
            y += dy[k];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> finedust[i][j];
            if (finedust[i][j] == -1) {
                x = i;
                y = j;
            }
        }
    }
    x -= 1;

    // 로직
    while (t--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (finedust[i][j] <= 0) continue;
                // 1) 인접한 칸 개수
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && finedust[nx][ny] >= 0) {
                        cnt += 1;
                    }
                }
                // 2) 확산되는 양
                if (cnt > 0) {
                    int val = finedust[i][j] / 5;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < m && finedust[nx][ny] >= 0) {
                            diffusion[nx][ny] += val;
                        }
                    }
                    finedust[i][j] = finedust[i][j] - cnt * val;
                }
            }
        }
        // 3) 확산된 값 더하기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (finedust[i][j] == -1) continue;
                finedust[i][j] += diffusion[i][j];
                diffusion[i][j] = 0;
            }
        }
        // 4) 공기청정기의 작동
        airPurifier(x, y, 1); // 위쪽으로 작동
        airPurifier(x + 1, y, 3); // 아래쪽으로 작동
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (finedust[i][j] >= 0) {
                ans += finedust[i][j];
            }
        }
    }

    // 출력 및 종료 
    cout << ans << '\n';
    return 0;
}
