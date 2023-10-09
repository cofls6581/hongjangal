#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
// #pragma warning(disable:4996)

using namespace std;

const int n_mx = 24, p_mx = 34;
typedef pair<int, int> pp;
int n, playerN, k, score[p_mx];
vector<int> gun[n_mx][n_mx];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
struct Info {
    int y, x, dir;
};
struct player {
    int y, x, dir, power, gun;

    bool operator<(const player& b) const {
        if ((power + gun) == (b.power + b.gun)) return power < b.power;
        else return (power + gun) < (b.power + b.gun);
    }
};
vector<player> players;

void Input() {
    cin >> n >> playerN >> k;
    int r, c, d, s, p;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p;
            if (p != 0) gun[i][j].push_back(p);
        }
    }
    for (int i = 0; i < playerN; ++i) {
        cin >> r >> c >> d >> s;
        players.push_back({ r - 1,c - 1,d,s,0 });
    }
}

bool inRange(int y, int x) {
    return y >= 0 && y < n&& x >= 0 && x < n;
}

Info getNextPos(int playerIdx) { // 플레이어가 이동할 위치, 방향 리턴
    int nextDir = players[playerIdx].dir;
    int ny = players[playerIdx].y + dy[nextDir];
    int nx = players[playerIdx].x + dx[nextDir];
    if (!inRange(ny, nx)) {
        nextDir = (nextDir + 2) % 4;
        ny = players[playerIdx].y + dy[nextDir];
        nx = players[playerIdx].x + dx[nextDir];
    }
    return { ny, nx, nextDir };
}

int findPlayer(int y, int x) {
    for (int i = 0; i < playerN; ++i) {
        if (players[i].y == y && players[i].x == x) return i;
    }
    return -1;
}

void compareGuns(int playerIdx) { // 항상 플레이어가 해당 위치로 이동한 후에 그 칸의 총들과 비교
    int y = players[playerIdx].y;
    int x = players[playerIdx].x;
    int pGun = players[playerIdx].gun;
    gun[y][x].push_back(pGun);
    sort(gun[y][x].begin(), gun[y][x].end(), greater<>());
    players[playerIdx].gun = gun[y][x][0];
    gun[y][x].erase(gun[y][x].begin());
}

void movePlayer(int playerIdx, Info nextPos) { // 플레이어를 실제로 움직임
    players[playerIdx].y = nextPos.y;
    players[playerIdx].x = nextPos.x;
    players[playerIdx].dir = nextPos.dir;
}

void loserActions(int loserIdx) {
    int cur_y = players[loserIdx].y;
    int cur_x = players[loserIdx].x;
    int cur_dir = players[loserIdx].dir;
    // 총 내려놓기
    gun[cur_y][cur_x].push_back(players[loserIdx].gun);
    players[loserIdx].gun = 0;
    // 다음 위치 찾기
    int ny = cur_y + dy[cur_dir];
    int nx = cur_x + dx[cur_dir];
    while (!inRange(ny, nx) || findPlayer(ny, nx) != -1) {
        cur_dir = (cur_dir + 1) % 4;
        ny = cur_y + dy[cur_dir];
        nx = cur_x + dx[cur_dir];
    }
    // 다음 위치로 이동 및 방향 설정
    movePlayer(loserIdx, { ny,nx,cur_dir });
    // 총 비교
    compareGuns(loserIdx);
}

void getScore(int winnerIdx, int loserIdx) {
    int winnerVal = players[winnerIdx].gun + players[winnerIdx].power;
    int loserVal = players[loserIdx].gun + players[loserIdx].power;
    score[winnerIdx] += (winnerVal - loserVal);
}

void fight(int playerIdx, int rivalIdx) {
    if (players[rivalIdx] < players[playerIdx]) { // 플레이어가 이김
        getScore(playerIdx, rivalIdx);
        loserActions(rivalIdx);
        compareGuns(playerIdx);
    }
    else { // 라이벌이 이김
        getScore(rivalIdx, playerIdx);
        loserActions(playerIdx);
        compareGuns(rivalIdx);
    }
}

void Proc() {
    for (int turn = 0; turn < k; ++turn) {
        for (int playerIdx = 0; playerIdx < playerN; ++playerIdx) {
            Info nextPos = getNextPos(playerIdx); // 플레이어의 다음 위치, 방향
            int rivalIdx = findPlayer(nextPos.y, nextPos.x);
            movePlayer(playerIdx, nextPos);

            if (rivalIdx == -1) {
                compareGuns(playerIdx);
            }
            else {
                fight(playerIdx, rivalIdx);
            }
        }
    }
}

void Output() {
    for (int i = 0; i < playerN; ++i) {
        cout << score[i] << ' ';
    }
    cout << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout); 

    Input();
    Proc();
    Output();

    return 0;
}
