#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n, m;
int a[55][55];
int d[55][55];
int ans = 0;

//대각선 포함 8방향
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};

int bfs(int sx, int sy) {
    //초기 세팅
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            d[i][j] = -1;
        }
    }
    d[sx][sy] = 0;

    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); 
        q.pop();

        for (int k=0; k<8; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            
            if (0 <= nx && nx < n && 0 <= ny && ny < m) { //범위 체크
                if (d[nx][ny] == -1) { //방문 x
                    if (a[nx][ny] == 1) { //상어 o
                        return d[x][y]+1;
                    } 
                    else { //상어 x
                        q.push(make_pair(nx,ny));
                        d[nx][ny] = d[x][y] + 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    //로직
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 0) {
                int dist = bfs(i, j);
                if (ans < dist) ans = dist;
            }
        }
    }
    //output
    cout << ans << '\n';
    return 0;
}
