#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

const int mx = 54;
typedef pair<int, int> pp;
int n, m, a[mx][mx], ans = INT_MAX;
vector<pp> c;

int calc(vector<pp>& v) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1) {
                int tmp = INT_MAX;
                for (pp ch : v) {
                    tmp = min(tmp, abs(i - ch.first) + abs(j - ch.second));
                }
                ret += tmp;
            }
        }
    }
    return ret;
}

void go(int idx, vector<pp>& v) {
    if (v.size() == m) {
        // v에 담긴 치킨집들로 도시의 치킨거리 구하기
        ans = min(ans, calc(v));
        return;
    }
    else if (v.size() && v.size() < m) {
        // v에 담긴 치킨집들로 도시의 치킨거리 구하기
        ans = min(ans, calc(v));
    }
    for (int i = idx + 1; i < c.size(); ++i) {
        v.push_back(c[i]);
        go(i, v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 2) c.push_back({ i,j });
        }
    }
    vector<pp> v;
    go(-1, v);
    cout << ans << '\n';

    return 0;
}
