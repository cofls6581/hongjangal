#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int a[50][50];
int d[50][50];
int room[50 * 50];

int bfs(int x, int y, int rooms) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    d[x][y] = rooms;
    int cnt = 0;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cnt++;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (d[nx][ny] != 0) continue;
            if (a[x][y] & (1 << k)) continue;
            q.push(make_pair(nx, ny));
            d[nx][ny] = rooms;
        }
    }
    return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> m >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
  
    // 방의 개수
    int rooms = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (d[i][j] == 0) {
                rooms += 1;
                room[rooms] = bfs(i, j, rooms);
            }
        }
    }
    cout << rooms << '\n';
    
    // 가장 큰 방
    int ans = 0;
    for (int i=1; i<=rooms; i++) {
        if (ans < room[i]) {
            ans = room[i];
        }
    }
    cout << ans << '\n';

    // 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
    ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x = i;
            int y = j;
            for (int k=0; k<4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (d[nx][ny] == d[x][y]) continue;
                if (a[x][y] & (1<<k)) {
                    if (ans < room[d[x][y]]+room[d[nx][ny]]) {
                        ans = room[d[x][y]]+room[d[nx][ny]];
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
