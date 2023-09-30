#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;
const int n_mx = 3, p_mx = 60;
int n, arr[n_mx + 4];
int dx[6][3] = { {9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,3,9},{1,9,3} };
int visited[p_mx + 3][p_mx + 3][p_mx + 3];

struct state {
    int a, b, c;
};

int bfs(int a, int b, int c) {
    queue<state> q;
    q.push({ a,b,c });
    visited[a][b][c] = 1;

    while (q.size()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        if (visited[0][0][0]) break;

        for (int i = 0; i < 6; ++i) {
            int na = max(0, a - dx[i][0]);
            int nb = max(0, b - dx[i][1]);
            int nc = max(0, c - dx[i][2]);
            if (visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({ na,nb,nc });
        }
    }
    return visited[0][0][0] - 1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << bfs(arr[0], arr[1], arr[2]) << '\n';

    return 0;
}
