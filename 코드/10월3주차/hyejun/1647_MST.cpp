#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int n_mx = 100004, m_mx = 1000004;
int n, m;
struct edge {
    int a, b, cost;

    bool operator<(const edge& b) const {
        return cost < b.cost;
    }
};
vector<edge> e;
int parent[n_mx];

void init() {
    for (int i = 0; i < n; ++i) parent[i] = i;
}

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return true;
    parent[a] = b;
    return false;
}

int mst() {
    int total = 0, edgeCnt = 0;
    init();

    sort(e.begin(), e.end());
    for (int i = 0; i < m; ++i) {
        if (!merge(e[i].a, e[i].b)) {
            edgeCnt++;
            total += e[i].cost;
        }
        if (edgeCnt == n - 1) return total - e[i].cost;
    }
    return -1; // 모든 정점 연결 불가능한 경우
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        e.push_back({ a,b,c });
    }
    cout << mst() << '\n';

    return 0;
}
