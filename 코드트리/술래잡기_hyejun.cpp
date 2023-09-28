#include <iostream>
#include <cmath>
// #pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int n_mx = 104;
int n, runN, treeN, k, ans, catcherSeqLen;
int dy[] = { 1,0,-1,0 }; // 하 우 상 좌 (달팽이 채울때 쓰기 위해 이 순서로 결정)
int dx[] = { 0,1,0,-1 };
int tree[n_mx][n_mx];
int seqMap[n_mx][n_mx];
pp catcherSeq[2 * n_mx * n_mx];

inline bool inRange(int y, int x) {
    return (y >= 0) && (y < n) && (x >= 0) && (x < n);
}

struct catcher { // 술래
    int y, x, seqIdx;
} catcher;

struct runner { // 도망자
    int y, x, dir, alive; // 생존 여부

    void move() {
        if (!alive) return; // 잡혀서 사라진 도망자인 경우 아무것도 하지 않음
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (!inRange(ny, nx)) {
            dir ^= 2; // (dir + 2) % 4
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        if (ny == catcher.y && nx == catcher.x) return; // 술래가 있는 칸인 경우 이동하지 않음
        y += dy[dir];
        x += dx[dir];
    }
} runners[n_mx * n_mx];

void Input() {
    cin >> n >> runN >> treeN >> k;
    int x, y, d;
    for (int i = 0; i < runN; ++i) {
        cin >> x >> y >> d;
        if (d == 2) runners[i] = { x - 1,y - 1,0,1 };
        else runners[i] = { x - 1,y - 1,d,1 };
    }
    for (int i = 0; i < treeN; ++i) {
        cin >> x >> y;
        tree[x - 1][y - 1] = 1;
    }
}

void getCatcherSeq() {
    // 달팽이 배열 채워두기 (각 칸에 술래가 몇번째로 도달하는지 구해두기 위해서)
    int y = 0, x = 0, cnt = n * n - 1, d = 0;
    seqMap[y][x] = cnt--;

    while (cnt >= 0) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (!inRange(ny, nx) || seqMap[ny][nx] != 0) d = (d + 1) % 4;
        y += dy[d];
        x += dx[d];
        seqMap[y][x] = cnt--;
    }

    // 술래 위치 1차원 배열 만들기
    catcherSeqLen = 2 * n * n - 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 이 칸에 몇번째로 도달하는지 저장해둔 seqMap을 인덱스로 삼아서 저장하기
            int order = seqMap[i][j];
            catcherSeq[order] = make_pair(i, j);
            order = catcherSeqLen - order;
            catcherSeq[order] = make_pair(i, j);
        }
    }
}

void moveRunner() {
    for (int i = 0; i < runN; ++i) {
        int dist = abs(catcher.y - runners[i].y) + abs(catcher.x - runners[i].x);
        if (dist > 3) continue;
        runners[i].move();
    }
}

void moveCatcher() {
    int nextSeqIdx = (catcher.seqIdx + 1) % catcherSeqLen;
    catcher = { catcherSeq[nextSeqIdx].first, catcherSeq[nextSeqIdx].second, nextSeqIdx };
}

int doCatch () {
    int catchCnt = 0;
    for (int i = 0; i < 3; ++i) { // 술래의 시야는 현재칸 포함 3칸
        int dy_c = catcherSeq[catcher.seqIdx + 1].first - catcherSeq[catcher.seqIdx].first;
        int dx_c = catcherSeq[catcher.seqIdx + 1].second - catcherSeq[catcher.seqIdx].second;
        int ny = catcher.y + dy_c * i;
        int nx = catcher.x + dx_c * i;
        if (!inRange(ny, nx) || tree[ny][nx]) continue;
        for (int j = 0; j < runN; ++j) {
            if (runners[j].y == ny && runners[j].x == nx && runners[j].alive == 1) {
                catchCnt++;
                runners[j].alive = 0;
            }
        }
    }
    return catchCnt;
}

void Simul() {
    // 전처리
    getCatcherSeq(); // 술래 위치 저장된 배열 생성
    catcher = { catcherSeq[0].first, catcherSeq[0].second,0 }; // 술래 초기 위치 세팅

    // 시뮬레이션
    for (int turn = 1; turn <= k; ++turn) {
        moveRunner();
        moveCatcher();
        ans += turn * doCatch();
    }
    cout << ans << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout);

    Input();
    Simul();

    return 0;
}
