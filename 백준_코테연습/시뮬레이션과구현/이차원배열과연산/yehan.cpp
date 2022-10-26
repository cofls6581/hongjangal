#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n = 3;
int m = 3;
int a[100][100];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int r, c, k;
    cin >> r >> c >> k;
    r -= 1;
    c -= 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (a[r][c] == k) {
        cout << 0 << '\n';
        return 0;
    }

    for (int t = 1; t <= 100; t++) {
        if (n >= m) { // R연산
            int col = m;
            for (int i = 0; i < n; i++) { // 각각의 수 등장 횟수 파악하기
                map<int, int> d;
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 0) continue;
                    d[a[i][j]] += 1;
                }

                vector<pair<int, int>> v; // 정렬하기
                for (auto& p : d) {
                    v.push_back(make_pair(p.second, p.first));
                }
                sort(v.begin(), v.end());

                int l = min((int)v.size(), 50);
                for (int j = 0; j < l; j++) { // 배열에 올바르게 숫자 넣어주기
                    a[i][j * 2] = v[j].second;
                    a[i][j * 2 + 1] = v[j].first;
                }
                for (int j = l * 2; j < 100; j++) { // 남는 공간 채우기
                    a[i][j] = 0;
                }
                if (col < (int)v.size() * 2) {
                    col = (int)v.size() * 2;
                }
            }
            m = col;
        }
        else { // C연산
            int row = n;
            for (int j = 0; j < m; j++) {
                map<int, int> d;
                for (int i = 0; i < n; i++) {
                    if (a[i][j] == 0) continue;
                    d[a[i][j]] += 1;
                }

                vector<pair<int, int>> v;
                for (auto& p : d) {
                    v.push_back(make_pair(p.second, p.first));
                }
                sort(v.begin(), v.end());

                int l = min((int)v.size(), 50);
                for (int i = 0; i < l; i++) {
                    a[i * 2][j] = v[i].second;
                    a[i * 2 + 1][j] = v[i].first;
                }
                for (int i = l * 2; i < 100; i++) {
                    a[i][j] = 0;
                }
                if (row < (int)v.size() * 2) {
                    row = (int)v.size() * 2;
                }
            }
            n = row;
        }

        if (a[r][c] == k) {
            cout << t << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
