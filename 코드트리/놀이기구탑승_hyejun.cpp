#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

const int mx = 24;
int n;
int a[mx][mx];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
vector<int> v[mx * mx];

struct info {
    int like;
    int empty;
    int row;
    int col;

    bool operator<(const info& info2) const {
        if (like != info2.like) return like < info2.like;
        if (empty != info2.empty) return empty < info2.empty;
        if (row != info2.row) return row > info2.row;
        return col > info2.col;
    }
};

pair<int, int> search(int n0, priority_queue<info>& pq) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j]) continue; // 빈칸 X
            int li = 0, em = 0;
            for (int k = 0; k < 4; ++k) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (a[ny][nx] == 0) {
                    em++;
                }
                else {
                    for (int idx = 0; idx < 4; ++idx) {
                        if (a[ny][nx] == v[n0][idx]) {
                            li++;
                            break;
                        }
                    }
                }
            }
            pq.push({ li,em,i,j });
        }
    }

    struct info top = pq.top();
    return make_pair(top.row, top.col);
}

int calc() {
    int score = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int li = 0;
            for (int k = 0; k < 4; ++k) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                for (int idx = 0; idx < 4; ++idx) {
                    if (a[ny][nx] == v[a[i][j]][idx]) {
                        li++;
                        break;
                    }
                }
            }
            if (li != 0) {
                score += pow(10, li - 1);
            }
        }
    }
    return score;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    int n0, like;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> n0;
            for (int k = 0; k < 4; ++k) {
                cin >> like;
                v[n0].push_back(like);
            }

            // 모든 칸에 대해 우선순위 조사
            priority_queue<info> pq;
            int y, x;
            tie(y, x) = search(n0, pq);
            a[y][x] = n0;
        }
    }

    // 최종 점수 계산
    cout << calc() << '\n';

    return 0;
}
