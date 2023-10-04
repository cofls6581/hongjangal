#include <iostream>
#include <algorithm>
#include <queue>
// #pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 1004;
const int INF = 1e9;
int r, c, jy, jx, fire_visited[mx][mx], person_visited[mx][mx], ans;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
char a[mx][mx];
queue<pp> q;

bool inRange(int y, int x) {
    return y >= 0 && y < r&& x >= 0 && x < c;
}

void fireBFS() { // 불 최단거리 계산
    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!inRange(ny, nx)) continue;
            if (fire_visited[ny][nx] != INF || a[ny][nx] == '#') continue;
            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
}

void personBFS() { // 지훈 최단거리 계산
    q.push(make_pair(jy, jx));
    person_visited[jy][jx] = 1;

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y == 0 || y == r - 1 || x == 0 || x == c - 1) {
            ans = person_visited[y][x];
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!inRange(ny, nx)) continue;
            if (person_visited[ny][nx] || a[ny][nx] == '#') continue;
            if (fire_visited[ny][nx] <= person_visited[y][x] + 1) continue; // 지훈이가 더 빨리 도달해야 함
            person_visited[ny][nx] = person_visited[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout); 

    cin >> r >> c;
    // 불 최단거리 초기화 (불이 아예 없을 수도 있음)
    fill(&fire_visited[0][0], &fire_visited[0][0] + mx * mx, INF);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'F') {
                fire_visited[i][j] = 1;
                q.push(make_pair(i, j));
            }
            else if (a[i][j] == 'J') {
                jy = i;
                jx = j;
            }
        }
    }

    fireBFS();
    personBFS();
    if (ans != 0) cout << ans << '\n';
    else cout << "IMPOSSIBLE" << '\n';

    return 0;
}
