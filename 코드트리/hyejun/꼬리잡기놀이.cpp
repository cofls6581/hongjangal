#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
// #pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int n_mx = 24;
int n, teamN, k, a[n_mx][n_mx], visited[n_mx][n_mx], ans;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void Input() {
    cin >> n >> teamN >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
}

bool inRange(int y,int x) {
    return y >= 0 && y < n&& x >= 0 && x < n;
}

void dfs(int y, int x, vector<pp> &teammates) {
    visited[y][x] = 1;
    teammates.push_back(make_pair(y, x));
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!inRange(ny, nx) || visited[ny][nx]) continue;
        if (teammates.size() == 1 && a[ny][nx] != 2) continue; // 처음에 머리사람에서 탐색할때는 무조건 2 방향으로 탐색하기
        if (a[ny][nx] == 2 || a[ny][nx] == 3) {
            dfs(ny, nx, teammates);
        }
    }
}

vector<pp> getTeamMates(pp head) {
    memset(visited, 0, sizeof(visited));
    vector<pp> teammates;
    dfs(head.first, head.second, teammates);
    return teammates;
}

void moveOneStep(vector<pp> teammates) {
    int y = teammates[0].first;
    int x = teammates[0].second;
    int ny, nx;
    for (int i = 0; i < 4; ++i) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (!inRange(ny, nx)) continue;
        if (a[ny][nx] == 4 || a[ny][nx] == 3) break; // 바로 앞이 이동선일수도 있고, 꼬리일수도 있음
    }
    vector<pp> newLoc;
    for (pp each : teammates) {
        y = each.first;
        x = each.second;
        // 새롭게 이동할 좌표 모두 저장 (밑에서 한번에 바꾸기) (<- 이동선을 팀원이 꽉 채울 경우에 대한 예외 처리)
        newLoc.push_back(make_pair(ny, nx));
        ny = y;
        nx = x;
        a[y][x] = 4;
    }
    // 이동
    for (int i = 0; i < newLoc.size(); ++i) {
        if (i == 0) {
            a[newLoc[i].first][newLoc[i].second] = 1;
        }
        else if (i == newLoc.size() - 1) {
            a[newLoc[i].first][newLoc[i].second] = 3;
        }
        else {
            a[newLoc[i].first][newLoc[i].second] = 2;
        }
    }
}

vector<vector<pp>> detectAllTeams() {
    vector<vector<pp>> teams;
    // 머리사람 찾기
    vector<pp> heads;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1) heads.push_back(make_pair(i, j));
        }
    }
    // 각 머리사람의 팀메이트들 구하기
    for (pp head : heads) {
        vector<pp> teammates = getTeamMates(head);
        teams.push_back(teammates);
    }
    return teams;
}

void moveAllTeams() { // 모든 팀 사람들 한칸씩 이동하기
    vector<vector<pp>> teams = detectAllTeams();
    for (vector<pp> teammates : teams) {
        moveOneStep(teammates);
    }
}

pp throwBall(int round) { // 공 던지고 얻는 사람 리턴하기
    round %= (4 * n);
    if (round < n) {
        for (int i = 0; i < n; ++i) {
            if (a[round][i] > 0 && a[round][i] < 4) return make_pair(round, i);
        }
    }
    else if (round < 2 * n) {
        round -= n;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i][round] > 0 && a[i][round] < 4) return make_pair(i, round);
        }
    }
    else if (round < 3 * n) {
        round -= 2 * n;
        for (int i = n - 1; i >= 0; --i) {
            if (a[n - 1 - round][i] > 0 && a[n - 1 - round][i] < 4) return make_pair(n - 1 - round, i);
        }
    }
    else {
        round -= 3 * n;
        for (int i = 0; i < n; ++i) {
            if (a[i][n - 1 - round] > 0 && a[i][n - 1 - round] < 4) return make_pair(i, n - 1 - round);
        }
    }
    return make_pair(-1, -1); // 공을 얻은 사람이 없으면 (-1, -1) 리턴
}

int getScoreAndReverse(pp target) { // 점수 획득하고 공 얻은 팀 방향 바꾸기
    vector<vector<pp>> teams = detectAllTeams();
    // target이 팀에서 몇번째(n)인지 구하고 n*n 리턴, 해당 팀의 방향 전환
    for (int i = 0; i < teams.size(); ++i) {
        for (int j = 0; j < teams[i].size(); ++j) {
            if (teams[i][j] == target) {
                // teams[i]의 머리와 꼬리 바꿔주기
                pp head = teams[i][0];
                pp tail = teams[i][teams[i].size() - 1];
                swap(a[head.first][head.second], a[tail.first][tail.second]);
                return (j + 1) * (j + 1);
            }
        }
    }
}

void Simul() {
    for (int round = 0; round < k; ++round) {
        moveAllTeams();
        pp target = throwBall(round);
        // cout << "공 얻은 사람: " << target.first << ", " << target.second << '\n';
        if (target != make_pair(-1, -1)) ans += getScoreAndReverse(target);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout);

    Input();
    Simul();
    cout << ans << '\n';

    return 0;
}
