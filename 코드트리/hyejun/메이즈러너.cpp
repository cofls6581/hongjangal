#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
// #pragma warning(disable:4996)

using namespace std;
typedef pair<int, int> pp;
const int mx = 14, INF = INT_MAX;
int n, m, k, a[mx][mx], totalCnt;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 }; // 상하좌우

void Input() {
    cin >> n >> m >> k;
    int w;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> w;
            a[i][j] = -w;
        }
    }
    int y, x;
    for (int i = 0; i < m; ++i) {
        cin >> y >> x;
        a[y][x]++;
    }
    cin >> y >> x; 
    a[y][x] = -10;
}

bool inRange(int y, int x) {
    return y > 0 && y <= n && x > 0 && x <= n;
}

pp findExit() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == -10) return make_pair(i, j);
        }
    }
}

void moveAll() {
    int newA[mx][mx] = { 0, };
    pp ex = findExit();
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            if (a[y][x] < 0) {
                newA[y][x] = a[y][x];
                continue;
            }
            if (a[y][x] == 0) continue; // 0인 칸은 복사 X
            int cur_dist = abs(y - ex.first) + abs(x - ex.second);
            int min_dist = cur_dist, min_ny, min_nx;
            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (!inRange(ny, nx)) continue;
                if (a[ny][nx] <= -1 && a[ny][nx] >= -9) continue;
                int tmp = abs(ny - ex.first) + abs(nx - ex.second);
                if (tmp < min_dist) {
                    min_dist = tmp;
                    min_ny = ny;
                    min_nx = nx;
                }
            }
            if (min_dist == cur_dist) { // 이동 불가능하면 그대로 복사
                newA[y][x] += a[y][x];
            }
            else {
                totalCnt += a[y][x];
                if (a[min_ny][min_nx] == -10) continue; // 탈출
                newA[min_ny][min_nx] += a[y][x];
            }
        }
    }
    copy(&newA[0][0], &newA[0][0] + mx * mx, &a[0][0]);
}

void subRotate(int y, int x, int d) {
    int part[mx][mx] = { 0, };
    int cp[mx][mx] = { 0, };
    // 떼어오기
    for (int i = y; i <= y + d; ++i) {
        for (int j = x; j <= x + d; ++j) {
            part[i - y + 1][j - x + 1] = a[i][j];
        }
    }
    // 시계방향 90도 회전
    int N = d + 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (-9 <= part[i][j] && part[i][j] <= -1) part[i][j]++;
            cp[j][N + 1 - i] = part[i][j];
        }
    }
    // 다시 실제 배열에 복붙
    for (int i = y; i <= y + d; ++i) {
        for (int j = x; j <= x + d; ++j) {
            a[i][j] = cp[i - y + 1][j - x + 1];
        }
    }
}

void rotateSquare() {
    // 정사각형 길이 결정
    int min_dist = INF;
    pp ex = findExit();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] <= 0) continue;
            int dist = max(abs(i - ex.first), abs(j - ex.second));
            min_dist = min(min_dist, dist);
        }
    }
    // 정사각형 좌상단 결정
    int best_y = 0, best_x = 0;
    for (int i = 1; i <= n - min_dist; ++i) {
        for (int j = 1; j <= n - min_dist; ++j) {
            bool flagP = 0, flagE = 0;
            for (int r = i; r <= i + min_dist; ++r) {
                for (int c = j; c <= j + min_dist; ++c) {
                    if (a[r][c] > 0) flagP = 1;
                    if (a[r][c] == -10) flagE = 1;
                }
            }
            if (flagP && flagE) {
                best_y = i;
                best_x = j;
                break;
            }
        }
        if (best_y != 0) break;
    }
    subRotate(best_y, best_x, min_dist);
}

bool isFinish() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] > 0) return false;
        }
    }
    return true;
}

void Proc() {
    for (int tm = 1; tm <= k; ++tm) {
        moveAll();
        if (isFinish()) break;
        rotateSquare();
    }
    pp ex = findExit();
    cout << totalCnt << '\n';
    cout << ex.first << " " << ex.second << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout); 

    Input();
    Proc();

    return 0;
}
