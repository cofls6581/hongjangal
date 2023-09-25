#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
// #pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int n_mx = 4, t_mx = 25, dir_mx = 8, disappear_mx = 2, pdir_mx = 4;
int m, t, turn = 1;
pp pman;
int dy_m[] = { -1,-1,0,1,1,1,0,-1 };
int dx_m[] = { 0,-1,-1,-1,0,1,1,1 };
int dy_p[] = { -1,0,1,0 };
int dx_p[] = { 0,-1,0,1 };
int monster[t_mx + 1][n_mx][n_mx][dir_mx]; // t 턴에 (r, c) 위치에 있는 방향이 d 인 몬스터 개수
int dead[n_mx][n_mx][disappear_mx + 1]; // (r, c) 위치에 있고 소멸되기까지 x 턴 남은 시체 개수

bool inRange(int y, int x) {
    return (y >= 0) && (y < n_mx) && (x >= 0) && (x < n_mx);
}

tuple<int, int, int> getNextPos(int y, int x, int dir) {
    for (int i = 0; i < dir_mx; ++i) {
        // 45도씩 반시계 방향으로 회전
        int n_dir = (dir + i + dir_mx) % dir_mx;
        int ny = y + dy_m[n_dir];
        int nx = x + dx_m[n_dir];
        if (!inRange(ny, nx)) continue;
        if (dead[ny][nx][0] || dead[ny][nx][1]) continue; // 시체
        if (pman.first == ny && pman.second == nx) continue; // 팩맨
        return make_tuple(ny, nx, n_dir);
    }
    // 8개 방향 모두 이동 불가하면 기존 위치 반환
    return make_tuple(y, x, dir);
}

void moveMonster() {
    for (int i = 0; i < n_mx; ++i) {
        for (int j = 0; j < n_mx; ++j) {
            for (int k = 0; k < dir_mx; ++k) {
                tuple<int, int, int> next_pos = getNextPos(i, j, k);
                int next_y, next_x, next_dir;
                tie(next_y, next_x, next_dir) = next_pos;
                monster[turn][next_y][next_x][next_dir] += monster[turn - 1][i][j][k];
            }
        }
    }
}

int getKillCnt(int first,int second, int third) {
    int dir_list[] = { first,second,third };
    int kill_cnt = 0;
    vector<pp> visited;
    int cur_y = pman.first;
    int cur_x = pman.second;

    for (int i = 0; i < 3; ++i) {
        int ny = cur_y + dy_p[dir_list[i]];
        int nx = cur_x + dx_p[dir_list[i]];
        if (!inRange(ny, nx)) return -1;
        // 방문한 곳은 다시 방문 X
        if (find(visited.begin(), visited.end(), make_pair(ny, nx)) == visited.end()) {
            for (int j = 0; j < dir_mx; ++j) {
                kill_cnt += monster[turn][ny][nx][j];
            }
            visited.push_back(make_pair(ny, nx));
        }
        cur_y = ny;
        cur_x = nx;
    }
    return kill_cnt;
}

void kill(tuple<int, int, int> route) {
    int f, s, t;
    tie(f, s, t) = route;
    int dir_list[] = { f,s,t };

    for (int i = 0; i < 3; ++i) {
        int ny = pman.first + dy_p[dir_list[i]];
        int nx = pman.second + dx_p[dir_list[i]];
        // (ny, nx) 위치에 있는 모든 방향의 몬스터 잡아먹기
        for (int j = 0; j < dir_mx; ++j) {
            // 시체 추가
            dead[ny][nx][disappear_mx] += monster[turn][ny][nx][j];
            monster[turn][ny][nx][j] = 0;
        }
        // 팩맨 이동
        pman.first = ny;
        pman.second = nx;
    }
}

void movePman() {
    int max_cnt = -1;
    tuple<int, int, int> best; // 몬스터 제일 많이 잡아먹을수있는 경로
    for (int i = 0; i < pdir_mx; ++i) {
        for (int j = 0; j < pdir_mx; ++j) {
            for (int k = 0; k < pdir_mx; ++k) {
                int kill_cnt = getKillCnt(i, j, k);
                if (max_cnt < kill_cnt) {
                    max_cnt = kill_cnt;
                    best = make_tuple(i, j, k);
                }
            }
        }
    }
    kill(best);
}

void deleteDead() {
    for (int i = 0; i < n_mx; ++i) {
        for (int j = 0; j < n_mx; ++j) {
            for (int k = 0; k < disappear_mx; ++k) {
                // 시체 소멸까지 남은 턴 하나씩 깎기
                dead[i][j][k] = dead[i][j][k + 1];
            }
            dead[i][j][disappear_mx] = 0;
        }
    }
}

void copyMonster() {
    for (int i = 0; i < n_mx; ++i) {
        for (int j = 0; j < n_mx; ++j) {
            for (int k = 0; k < dir_mx; ++k) {
                // 이전 턴에 몬스터가 있던 자리의 알 부화
                monster[turn][i][j][k] += monster[turn - 1][i][j][k];
            }
        }
    }
}

void simul() {
    // 이전 턴에 몬스터 있던 칸을 이용하면 되므로 따로 복제할 필요 X
    moveMonster();
    movePman();
    deleteDead();
    copyMonster();
}

int countMonster() {
    int cnt = 0;
    for (int i = 0; i < n_mx; ++i) {
        for (int j = 0; j < n_mx; ++j) {
            for (int k = 0; k < dir_mx; ++k) {
                cnt += monster[t][i][j][k];
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout);

    cin >> m >> t;
    int r, c, d;
    cin >> r >> c;
    pman.first = r - 1; pman.second = c - 1;
    for (int i = 0; i < m; ++i) {
        cin >> r >> c >> d;
        monster[0][r - 1][c - 1][d - 1]++;
    }
    for (int i = 0; i < t; ++i) { // t 턴 만큼 반복
        simul();
        turn++;
    }
    cout << countMonster() << '\n';

    return 0;
}
