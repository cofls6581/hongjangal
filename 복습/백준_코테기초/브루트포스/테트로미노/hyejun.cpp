/*
테트로미노 5가지 중 4가지(대칭, 회전 포함)는 모두 재귀함수로 깊이 3까지 탐색하고, 'ㅏ,ㅓ,ㅗ,ㅜ'는 따로 계산함
*/
#include <iostream>
#include <cstring>
#define MAX 500

using namespace std;

int n, m;
int a[MAX][MAX];
int tmp, ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool visited[MAX][MAX];

void solve(int x, int y, int sum, int cnt) {
    visited[x][y] = true;
    if (cnt == 3) {
        if (sum > ans) ans = sum;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!visited[nx][ny]) {
                solve(nx, ny, sum + a[nx][ny], cnt + 1);
                visited[nx][ny] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) { // 나머지 모양
        for (int j = 0; j < m; j++) {
            memset(visited, false, sizeof(visited));
            solve(i, j, a[i][j], 0);
        }
    }
    for (int i = 0; i < n; i++) { // ㅏ 모양
        for (int j = 0; j < m; j++) {
            if (i - 1 >= 0 && i + 1 < n && j - 1 >= 0) {
                tmp = a[i][j] + a[i - 1][j - 1] + a[i][j - 1] + a[i + 1][j - 1];
                if (tmp > ans) ans = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) { // ㅗ 모양
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && j - 1 >= 0 && j + 1 < m) {
                tmp = a[i][j] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
                if (tmp > ans) ans = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) { // ㅜ 모양
        for (int j = 0; j < m; j++) {
            if (i - 1 >= 0 && j - 1 >= 0 && j + 1 < m) {
                tmp = a[i][j] + a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1];
                if (tmp > ans) ans = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) { // ㅓ 모양
        for (int j = 0; j < m; j++) {
            if (i - 1 >= 0 && i + 1 < n && j + 1 < m) {
                tmp = a[i][j] + a[i - 1][j + 1] + a[i][j + 1] + a[i + 1][j + 1];
                if (tmp > ans) ans = tmp;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
