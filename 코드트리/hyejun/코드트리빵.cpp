#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
// #pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 19, m_mx = 34;
int n, m, grid[mx][mx], finishCnt, visited[mx][mx], finished[m_mx];
int dy[] = { -1,0,0,1 };
int dx[] = { 0,-1,1,0 };
struct player {
    int cy, cx, ty, tx;
} players[m_mx];

void Input() {
    cin >> n >> m;
    for (int i = 1; i <= n;  ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j]; // 1이면 베이스캠프
        }
    }
    int y, x;
    for (int i = 1; i <= m; ++i) {
        cin >> y >> x;
        players[i] = { -1,-1,y,x };
    }
}

bool inRange(int y, int x) {
    return y >= 1 && y <= n && x >= 1 && x <= n;
}

void move(int idx) { // 편의점까지 최단경로 구하기
    memset(visited, 0, sizeof(visited));
    queue<pp> q;
    pp adj[mx][mx];
    int sy = players[idx].cy, sx = players[idx].cx;
    int ty = players[idx].ty, tx = players[idx].tx;

    q.push(make_pair(sy, sx));
    visited[sy][sx] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == ty && x == tx) break; // 편의점 도착
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!inRange(ny, nx) || visited[ny][nx] || grid[ny][nx] == -1) continue;
            visited[ny][nx] = 1;
            adj[ny][nx] = make_pair(y, x);
            q.push(make_pair(ny, nx));
        }
    }
    // 경로 거슬러 올라가기
    queue<pp> qq;
    qq.push(make_pair(ty, tx));
    while (!qq.empty()) {
        int y = qq.front().first, x = qq.front().second;
        qq.pop();
        int ny = adj[y][x].first, nx = adj[y][x].second;
        if (!(ny == sy && nx == sx)) qq.push(make_pair(ny, nx));
        else {
            // (y, x) 로 이동
            players[idx].cy = y;
            players[idx].cx = x;
            // cout << "플레이어 " << idx << " 가 " << players[idx].cy << ", " << players[idx].cx << " 로 이동" << '\n';
            break;
        }
    }
}

void moveOneStep(int T) {
    for (int i = 1; i <= m; ++i) {
        if (make_pair(players[i].cy, players[i].cx) == make_pair(-1, -1)) continue;
        if (finished[i]) continue;
        move(i);
    }
}

void checkArrive(int T) {
    for (int i = 1; i <= m; ++i) {
        int y = players[i].cy;
        int x = players[i].cx;
        int ty = players[i].ty;
        int tx = players[i].tx;
        if (make_pair(y, x) == make_pair(-1, -1)) continue;
        if (finished[i]) continue;
        if (make_pair(y, x) == make_pair(ty, tx)) { // 최초 도착
            finished[i] = 1;
            finishCnt++;
            grid[y][x] = -1; // 못 지나감
        }
    }
}

void baseCamp(int T) {
    if (T > m) return;
    for (int idx = 1; idx <= m; ++idx) {
        if (idx == T) {
            memset(visited, 0, sizeof(visited));
            int ty = players[idx].ty;
            int tx = players[idx].tx;
            // 편의점으로부터 최단거리에 있는 베이스캠프 찾아서 이동, 다른사람들이 못지나가게 처리
            queue<pp> q;
            q.push(make_pair(ty, tx));
            visited[ty][tx] = 1;
            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                if (grid[y][x] == 1) { // 베이스캠프 찾음
                    players[idx].cy = y;
                    players[idx].cx = x;
                    grid[y][x] = -1;
                    // cout << "플레이어 " << idx << " 베캠 이동 -> 위치: " << players[idx].cy << ", " << players[idx].cx << '\n';
                    break;
                }
                for (int i = 0; i < 4; ++i) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (!inRange(ny, nx) || visited[ny][nx] || grid[ny][nx] == -1) continue;
                    visited[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

void Proc() {
    int T = 1;
    while (1) {
        moveOneStep(T);
        checkArrive(T);
        baseCamp(T);
        if (finishCnt == m) { // 모두 편의점에 도착
            cout << T << '\n';
            break;
        }
        T++;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout); 

    Input();
    Proc();

    return 0;
}
