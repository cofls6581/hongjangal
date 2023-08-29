#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 10004;
int n, m, visited[mx], cnt;
vector<int> adj[mx];
vector<pp> info; // {한번에 해킹할수있는 컴퓨터 수, 컴퓨터 번호}

void dfs(int x) {
    visited[x] = 1;
    cnt++;
    for (int i = 0; i < adj[x].size(); ++i) {
        int nx = adj[x][i];
        if (visited[nx]) continue;
        dfs(nx);
    }
}

bool cmp(pp a, pp b) {
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        fill(&visited[0], &visited[0] + mx, 0);
        cnt = 0;
        dfs(i);
        info.push_back({ cnt, i });
    }
    sort(info.begin(), info.end(), cmp);
    pp best = info[0];
    for (pp i : info) {
        if (i.first != best.first) break;
        cout << i.second << ' ';
    }
    cout << '\n';

    return 0;
}
