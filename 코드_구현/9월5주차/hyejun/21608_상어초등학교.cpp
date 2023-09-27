#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
// #pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 20;
int n;
int arr[mx * mx + 4][mx * mx + 4];
int board[mx + 4][mx + 4];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
pp where[mx * mx + 4];
struct info {
    int like;
    int empty;
    int r;
    int c;

    bool operator<(const info& b) const {
        if (like != b.like) return like < b.like;
        if (empty != b.empty) return empty < b.empty;
        if (r != b.r) return r > b.r;
        return c > b.c;
    }
};

void decide(int cur) {
    priority_queue<info> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j]) continue;
            int like_cnt = 0;
            int empty_cnt = 0;
            for (int k = 0; k < 4; ++k) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                for (int idx = 0; idx < 4; ++idx) {
                    if (board[ny][nx] == arr[cur][idx]) like_cnt++;
                }
                if (!board[ny][nx]) empty_cnt++;
            }
            pq.push({ like_cnt, empty_cnt, i, j });
        }
    }
    info pick = pq.top();
    board[pick.r][pick.c] = cur;
    where[cur] = make_pair(pick.r, pick.c);
}

int getScore() {
    int total = 0;
    int len = n * n;
    for (int i = 1; i <= len; ++i) {
        int like_cnt = 0;
        pp loc = where[i];
        for (int j = 0; j < 4; ++j) {
            int ny = loc.first + dy[j];
            int nx = loc.second + dx[j];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            for (int idx = 0; idx < 4; ++idx) {
                if (board[ny][nx] == arr[i][idx]) like_cnt++;
            }
        }
        if (like_cnt > 0) {
            total += pow(10, like_cnt - 1);
        }
    }
    return total;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout);

    cin >> n;
    int len = n * n;
    int a, b, c, d, e;
    for (int i = 0; i < len; ++i) {
        cin >> a >> b >> c >> d >> e;
        arr[a][0] = b; arr[a][1] = c; arr[a][2] = d; arr[a][3] = e;
        decide(a);
    }
    cout << getScore() << '\n';

    return 0;
}
