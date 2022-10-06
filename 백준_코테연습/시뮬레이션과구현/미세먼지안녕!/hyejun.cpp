#include <iostream>
#include <algorithm>

using namespace std;

int r, c, t;

int board[50][50]; // 각 칸의 미세먼지 양
int add[50][50]; // 각 칸에 더해질 양 (확산 결과)

int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };

int cleaner_x, cleaner_y;

void cleaner(int start_x, int start_y, int direction) {
    // 공기청정기 위쪽은 반시계, 아래쪽은 시계
    int x = start_x;
    int y = start_y + 1;
    int prev = 0;
    int k = 0; // 방향 설정을 위한 변수

    while (true) {
        if (x == start_x && y == start_y) break; // 공기청정기로 들어가면 정화됨
        swap(prev, board[x][y]);
        x += dx[k];
        y += dy[k];
        if (x < 0 || y < 0 || x >= r || y >= c) { // 범위 벗어난 경우
            // 복구
            x -= dx[k];
            y -= dy[k];
            // 방향 변경
            k += direction;
            k %= 4;
            // 이동
            x += dx[k];
            y += dy[k];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // input
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                cleaner_x = i;
                cleaner_y = j;
            }
        }
    }
    cleaner_x--;

    // solution
    while (t--) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // 미세먼지 확산
                if (board[i][j] <= 0) continue; // 미세먼지가 없거나 공기청정기가 있는 칸일 경우

                int cnt = 0; // 확산된 방향의 개수
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] >= 0) {
                        cnt++;
                    }
                }

                if (cnt > 0) { // 확산 가능한 경우
                    int amount = board[i][j] / 5; // 확산되는 양
                    
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] >= 0) {
                            // 우선 add에 확산되는 양 저장
                            add[nx][ny] += amount;
                        }
                    }

                    // 확산된만큼 빼기
                    board[i][j] -= amount * cnt;
                }
            }
        }
        // 마지막에 board에 더하기
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == -1) continue; // 공기청정기가 있는 칸은 확산 불가능이므로 제외
                board[i][j] += add[i][j];
                add[i][j] = 0; // 매초 초기화
            }
        }
        
        // 공기청정기
        cleaner(cleaner_x, cleaner_y, 1);
        cleaner(cleaner_x + 1, cleaner_y, 3);
    }

    // output
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] >= 0) {
                ans += board[i][j];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
