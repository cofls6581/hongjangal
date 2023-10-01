#include <iostream>
#include <cstring>
#define prev myprev
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 24;
int n, m, a[mx][mx], score, dir = 1, dice_num[3] = { 6,2,3 }, visited[mx][mx]; // dir 은 가고자 하는 방향 - 상우하좌(0,1,2,3) 순 & dice_num 은 주사위 밑면([0]), 앞면([1]), 오른쪽 옆면([2]) 에 쓰여진 숫자. 
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
pp dice = { 0,0 };

void range() {
    // 다음에 가고자 하는 위치가 범위를 벗어나면 조정
    int ny, nx;
    ny = dice.first + dy[dir];
    nx = dice.second + dx[dir];
    if (ny >= 0 && ny < n && nx >= 0 && nx < n) return;
    dir = (dir + 2) % 4;
}

void nextDir() {
    if (dice_num[0] > a[dice.first][dice.second]) dir = (dir + 1) % 4;
    else if (dice_num[0] < a[dice.first][dice.second]) dir = (dir - 1 + 4) % 4;
}

void move(int dir) {
    dice.first = dice.first + dy[dir];
    dice.second = dice.second + dx[dir];
}

int dfs(int y, int x) {
    int ret = 1;
    visited[y][x] = true;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (visited[ny][nx] || a[ny][nx] != a[y][x]) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

void calc() {
    memset(visited, 0, sizeof(visited));
    int ret = dfs(dice.first, dice.second);
    score += a[dice.first][dice.second] * ret;
}

void roll(int dir) {
    int prev[3];
    for (int i = 0; i < 3; ++i) {
        prev[i] = dice_num[i];
    }
    if (dir == 0) { // 상
        dice_num[0] = 7 - prev[1];
        dice_num[1] = prev[0];
    }
    else if (dir == 1) { // 우
        dice_num[0] = prev[2];
        dice_num[2] = 7 - prev[0];
    }
    else if (dir == 2) { // 하
        dice_num[0] = prev[1];
        dice_num[1] = 7 - prev[0];
    }
    else if (dir == 3) { // 좌
        dice_num[0] = 7 - prev[2];
        dice_num[2] = prev[0];
    }
}

void simul() {
    range();
    move(dir);
    roll(dir);
    calc();
    nextDir();
}

void go() {
    for (int i = 0; i < m; ++i) {
        simul();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    go();
    cout << score << '\n';

    return 0;
}
