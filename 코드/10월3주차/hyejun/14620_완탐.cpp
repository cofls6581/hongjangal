#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 14, INF = 987654321;
int n, a[mx][mx], totalCost = INF, visited[mx][mx];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
vector<pp> v;

bool check(int y, int x) {
    if (visited[y][x]) return false;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) return false;
    }
    return true;
}

void combi() {
    if (v.size() == 3) {
        int sm = 0;
        for (pp seed : v) {
            int y = seed.first;
            int x = seed.second;
            sm += a[y][x];
            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                sm += a[ny][nx];
            }
        }
        totalCost = min(totalCost, sm);
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (check(i, j)) {
                v.push_back(make_pair(i, j));
                visited[i][j] = 1;
                for (int k = 0; k < 4; ++k) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    visited[ny][nx] = 1;
                }

                combi();

                v.pop_back();
                visited[i][j] = 0;
                for (int k = 0; k < 4; ++k) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    visited[ny][nx] = 0;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    combi();

    cout << totalCost << '\n';

    return 0;
}
