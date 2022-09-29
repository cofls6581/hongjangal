#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool bfs(vector<vector<int>>& a, int l, int r) { // 연합 탐색 (인구 이동 여부 리턴)
    int n = a.size();
    vector<vector<bool>> check(n, vector<bool>(n, false));
    bool move = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j] == false) {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                check[i][j] = true;

                vector<pair<int, int>> united;
                united.push_back(make_pair(i, j));
                int sum = a[i][j]; // 연합국의 인구수 총 합

                while (!q.empty()) {
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n) { // 범위 검사
                            if (check[nx][ny]) continue;
                            int diff = abs(a[nx][ny] - a[x][y]);
                            if (l <= diff && diff <= r) { // 인구 차이 체크
                                q.push(make_pair(nx, ny));
                                united.push_back(make_pair(nx, ny));
                                check[nx][ny] = true;
                                move = true;
                                sum += a[nx][ny];
                            }
                        }
                    }
                }

                int val = sum / united.size(); // 연합 국가의 각 인구수
                while (!united.empty()) {
                    int x, y;
                    tie(x, y) = united.back();
                    united.pop_back();
                    a[x][y] = val;
                }

            }
        }
    }
    
    return move;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // input
    int n, l, r;
    cin >> n >> l >> r;
    vector<vector<int>> a(n, vector<int>(n)); // 인구수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // solution
    int cnt = 0; // 인구 이동 횟수
    while (true) {
        if (bfs(a, l, r)) {
            cnt += 1;
        }
        else {
            break;
        }
    }

    // output
    cout << cnt << '\n';

    return 0;
}
