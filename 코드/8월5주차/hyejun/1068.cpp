#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

const int mx = 54;
int n, root, target, ans, visited[mx], parent[mx];
vector<int> adj[mx];
int outDegree[mx];

void go(int x) {
    visited[x] = 1;
    if (x == target) {
        outDegree[parent[x]]--;
        if (outDegree[parent[x]] == 0) ans++;
        return;
    }
    if (outDegree[x] == 0) ans++;
    
    int len = adj[x].size();
    for (int i = 0; i < len; ++i) {
        int nx = adj[x][i];
        if (visited[nx]) continue;
        go(nx);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == -1) {
            root = i;
            continue;
        }
        else {
            adj[x].push_back(i);
            outDegree[x]++;
            parent[i] = x;
        }
    }
    cin >> target;
    go(root);
    cout << ans << '\n';

    return 0;
}
