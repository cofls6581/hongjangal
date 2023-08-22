#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 104;
int h, w;
string s;
int a[mx][mx];
int t[mx][mx];
vector<pp> v[mx];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    memset(t, -1, sizeof(t));
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> s;
        for (int j = 0; j < w; ++j) {
            a[i][j] = s[j];
            if (s[j] == 'c') {
                v[i].push_back(make_pair(i, j));
                t[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        // 각 행마다
        for (int j = v[i].size() - 1; j >= 0; --j) {
            int y, x;
            tie(y, x) = v[i][j];
            int nx = x + 1;
            while (1) {
                if (nx >= w) break;
                if (a[y][nx] == 'c') break;
                t[y][nx] = t[y][nx - 1] + 1;
                nx++;
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << t[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
