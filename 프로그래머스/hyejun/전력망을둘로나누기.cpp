#include <bits/stdc++.h>

using namespace std;

const int mx = 104;
int visited[mx];
vector<vector<int>> adj;

int dfs(int x) {
    int ret = 1;
    visited[x] = 1;
    for (int i = 0; i < adj[x].size(); ++i) {
        int nxt = adj[x][i];
        if (visited[nxt]) continue;
        ret += dfs(nxt);
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int ans = 987654321;
    int ex = 0;
    while (ex < n - 1) {
        memset(visited, 0, sizeof(visited));
        adj.clear(); adj.resize(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            if (i == ex) continue;
            adj[wires[i][0]].push_back(wires[i][1]);
            adj[wires[i][1]].push_back(wires[i][0]);
        }
        int res1 = dfs(wires[ex][0]);
        memset(visited, 0, sizeof(visited));
        int res2 = dfs(wires[ex][1]);
        ans = min(ans, abs(res1 - res2));
        ex++;
    }
    return ans;
}
