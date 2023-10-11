#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>
// #pragma warning(disable:4996)

using namespace std;
typedef pair<int, int> pp;
const int mx = 14;
const int INF = 987654321;
int n, m, k, visited[mx][mx], brokenCnt, broken[mx][mx];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
struct tower {
    int y, x, atk, lt, atked;

    bool operator<(const tower& b) const {
        if (atk != b.atk) return atk < b.atk;
        if (lt != b.lt) return lt > b.lt;
        if ((y + x) != (b.y + b.x)) return (y + x) > (b.y + b.x);
        return x > b.x;
    }

    bool operator>(const tower& b) const {
        if (atk != b.atk) return atk > b.atk;
        if (lt != b.lt) return lt < b.lt;
        if ((y + x) != (b.y + b.x)) return (y + x) < (b.y + b.x);
        return x < b.x;
    }
} towers[mx][mx];

void Input() {
    cin >> n >> m >> k;
    int atk;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> atk;
            towers[i][j] = { i,j,atk,0 };
        }
    }
}

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

pp getLoc(int y, int x) {
    y = (y + n) % n;
    x = (x + m) % m;
    return make_pair(y, x);
}

tower getAttacker(int turn) {
    tower attacker = { n,m,INF,-1 };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (towers[i][j].atk == 0) continue;
            if (towers[i][j] < attacker) attacker = towers[i][j];
        }
    }
    // cout << "공격자: " << attacker.y << ", " << attacker.x << '\n';
    if (make_pair(attacker.y, attacker.x) != make_pair(n, m)) {
        towers[attacker.y][attacker.x].atk += (n + m);
        towers[attacker.y][attacker.x].lt = turn;
    }
    // else cout << "공격자 선정 실패" << '\n';
    return towers[attacker.y][attacker.x];
}

bool lazer(tower atker, tower target, int turn) {
    memset(visited, 0, sizeof(visited));
    pp adj[mx][mx];
    queue<pp> q;
    q.push(make_pair(atker.y, atker.x));
    visited[atker.y][atker.x];
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (make_pair(y, x) == make_pair(target.y, target.x)) break;

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            while (!inRange(ny, nx)) {
                tie(ny, nx) = getLoc(ny, nx);
            }
            if (visited[ny][nx] || towers[ny][nx].atk <= 0) continue;
            visited[ny][nx] = 1;
            adj[ny][nx] = make_pair(y, x); // 거꾸로 저장
            q.push(make_pair(ny, nx));
        }
    }
    if (visited[target.y][target.x] == 0) return false;
    // 공격 대상을 공격 및 turn 저장하고, adj 따라서 순회하면서 turn 저장 및 공격
    queue<pp> qq;
    qq.push(make_pair(target.y, target.x));
    towers[target.y][target.x].atk -= atker.atk;
    towers[target.y][target.x].atked = turn;
    int val = atker.atk / 2;
    while (!qq.empty()) {
        int y = qq.front().first;
        int x = qq.front().second;
        qq.pop();
        int ny = adj[y][x].first;
        int nx = adj[y][x].second;
        if (make_pair(ny, nx) != make_pair(atker.y, atker.x)) {
            towers[ny][nx].atk -= val;
            towers[ny][nx].atked = turn;
            qq.push(make_pair(ny, nx));
        }
    }
    return true;
}

void bomb(tower atker, tower target, int turn) {
    towers[target.y][target.x].atk -= atker.atk;
    towers[target.y][target.x].atked = turn;
    int val = atker.atk / 2;
    int Dy[] = { -1,-1,0,1,1,1,0,-1 };
    int Dx[] = { 0,1,1,1,0,-1,-1,-1 };
    for (int i = 0; i < 8; ++i) {
        int ny = target.y + Dy[i];
        int nx = target.x + Dx[i];
        while (!inRange(ny, nx)) {
            tie(ny, nx) = getLoc(ny, nx);
        }
        if (make_pair(ny, nx) == make_pair(atker.y, atker.x) || towers[ny][nx].atk <= 0) continue;
        towers[ny][nx].atk -= val;
        towers[ny][nx].atked = turn;
    }
}

void attack(tower atker, int turn) {
    tower target = { n,m,-1,-1 };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (towers[i][j].atk == 0) continue;
            if (make_pair(i, j) == make_pair(atker.y, atker.x)) continue;
            if (towers[i][j] > target) target = towers[i][j];
        }
    }
    // cout << "공격 대상: " << target.y << ", " << target.x << '\n';
    if (make_pair(target.y, target.x) == make_pair(n, m)) {
        // cout << "공격 대상 선정 실패" << '\n';
        return;
    }
    // 레이저 공격
    bool lazerAtk = lazer(atker, target, turn);
    // 최단경로 없으면 포탄 공격
    if (!lazerAtk) {
        bomb(atker, target, turn);
    }
}

void fallDown() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (broken[i][j]) continue;
            if (towers[i][j].atk <= 0) {
                towers[i][j].atk = 0;
                broken[i][j] = 1;
                brokenCnt++;
            }
        }
    }
}

void prepare(int turn) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (towers[i][j].atk == 0 || towers[i][j].lt == turn || towers[i][j].atked == turn) continue;
            towers[i][j].atk += 1;
        }
    }
}

void Output() {
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (towers[i][j].atk <= 0) continue;
            ans = max(ans, towers[i][j].atk);
        }
    }
    cout << ans << '\n';
}

void Proc() {
    int val = n * m - 1;
    for (int turn = 1; turn <= k; ++turn) {
        tower atker = getAttacker(turn);
        attack(atker, turn);
        fallDown();
        if (brokenCnt == val) break;
        prepare(turn);
    }
    Output();
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout); 

    Input();
    Proc();

    return 0;
}
