#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n = 3;
int m = 3;
int a[100][100];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // input
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
        cout << 0 << '\n'; // 이미 a[r][c] == k 이면 최소시간은 0
        return 0;
    }

    // solution
    for (int t = 1; t <= 100; t++) {
        if (n >= m) { // R 연산
            int col = m; // 열의 개수 (변동)
            for (int i = 0; i < n; i++) {
                map<int, int> d; // 수의 등장 횟수
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 0) continue;
                    d[a[i][j]] += 1;
                }

                vector<pair<int, int>> v; // 정렬을 위해 일차원 배열에 넣기
                for (auto& p : d) {
                    v.push_back(make_pair(p.second, p.first)); // 등장 횟수가 우선
                }
                sort(v.begin(), v.end()); // 정렬

                int l = min((int)v.size(), 50); // 배열 크기
                for (int j = 0; j < l; j++) {
                    a[i][j * 2] = v[j].second; // 수
                    a[i][j * 2+1] = v[j].first; // 등장 횟수
                }
                for (int j = l * 2; j < 100; j++) {
                    a[i][j] = 0; // 남는 공간 채우기
                }
                if (col < (int)v.size() * 2) {
                    col = (int)v.size() * 2;
                }
            }
            m = col;
        }
        else { // C 연산
            int row = n; // 열의 개수 (변동)
            for (int j = 0; j < m; j++) {
                map<int, int> d; // 수의 등장 횟수
                for (int i = 0; i < n; i++) {
                    if (a[i][j] == 0) continue;
                    d[a[i][j]] += 1;
                }

                vector<pair<int, int>> v; // 정렬을 위해 일차원 배열에 넣기
                for (auto& p : d) {
                    v.push_back(make_pair(p.second, p.first)); // 등장 횟수가 우선
                }
                sort(v.begin(), v.end()); // 정렬

                int l = min((int)v.size(), 50); // 배열 크기
                for (int i = 0; i < l; i++) {
                    a[i * 2][j] = v[i].second; // 수
                    a[i * 2 + 1][j] = v[i].first; // 등장 횟수
                }
                for (int i = l * 2; i < 100; i++) {
                    a[i][j] = 0; // 남는 공간 채우기
                }
                if (row < (int)v.size() * 2) {
                    row = (int)v.size() * 2;
                }
            }
            n = row;
        }

        // output
        if (a[r][c] == k) {
            cout << t << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
