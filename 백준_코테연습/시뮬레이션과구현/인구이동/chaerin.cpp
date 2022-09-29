#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <cstdlib>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,l,r;
int ans = 0;

bool bfs(vector<vector<int>> &a, int l, int r) {
    vector<vector<bool>> visit(n, vector<bool>(n, false)); //visit 체크
    bool move = false; //이동여부 체크
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (visit[i][j] == false){
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                visit[i][j] = true;
                stack<pair<int,int>> s; //연합 인구 계산 위해 보존용
                s.push(make_pair(i,j));
                int sum = a[i][j];
                while (!q.empty()) {
                    int x, y;
                    tie(x,y) = q.front();
                    q.pop();
                    for (int k=0; k<4; k++) { //국경선 인접나라 체크
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                            if (visit[nx][ny]) continue;
                            int diff = abs(a[nx][ny] - a[x][y]);
                            if (l <= diff && diff <= r) { //인구 차이 검증
                                q.push(make_pair(nx,ny));
                                s.push(make_pair(nx,ny));
                                visit[nx][ny] = true;
                                move = true;
                                sum += a[nx][ny];
                            }
                        }
                    }
                }
                int val = sum / s.size(); //연합의 인구
                while (!s.empty()) { //연합 존재할 경우
                    int x, y;
                    tie(x,y) = s.top();
                    s.pop();
                    a[x][y] = val;
                }
            }
        }

    }
    return move;
}


int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin >> n >> l >> r;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    //logic+output
    while (true) { //인구이동할 때까지 반복
        if (bfs(a,l,r)) {
            ans += 1;
        } else {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
