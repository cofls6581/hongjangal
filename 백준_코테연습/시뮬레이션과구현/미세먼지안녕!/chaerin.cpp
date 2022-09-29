#include <iostream>
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int n, m, t;
int a[50][50]; //(r,c) 미세먼지 양
int b[50][50]; //확산 후 (r,c)에 더해질 양
int x,y;//위 공기청정기 위치
int ans = 0;

void airCleaner(int sx, int sy, int z) { 
    int prev = 0;
    int x = sx; int y = sy+1;
    int k = 0; //공기청정기 작동 방향
    while (true) {
        if (x == sx && y == sy) break; //한바퀴 돌고옴
        swap(prev, a[x][y]);
        x += dx[k]; y += dy[k]; //방향 다음 칸
        if (x < 0 || y < 0 || x >= n || y >= m) { //칸 끝났을 경우
            x -= dx[k]; y -= dy[k]; //되돌아가기
            k += z; k %= 4; //방향 바꾸기
            x += dx[k]; y += dy[k]; //바꾼 방향 이동
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin >> n >> m >> t;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) {
                x = i;
                y = j;
            }
        }
    }
    x -= 1;
    //로직
    while (t--) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] <= 0) continue; //미세먼지 없거나 공기청정기
                int cnt = 0;
                for (int k=0; k<4; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] >= 0) {
                        cnt += 1;
                    }
                }
                if (cnt > 0) { //상하좌우 이동가능한 횟수만큼 반복
                    int val = a[i][j]/5; //확산될 양
                    for (int k=0; k<4; k++) {
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] >= 0) {
                            b[nx][ny] += val; //확산 후 더해질 양
                        }
                    }
                    a[i][j] = a[i][j] - cnt*val; 
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == -1) continue;
                a[i][j] += b[i][j]; //확산 후 미세먼지양 저장
                b[i][j] = 0; //더해질 미세먼지 양 초기화
            }
        }
        airCleaner(x,y,1); //공기청정기 위방향
        airCleaner(x+1,y,3); //공기청정기 아래방향
    }

    //output
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] >= 0) {
                ans += a[i][j];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
