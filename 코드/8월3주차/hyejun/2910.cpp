#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

const int mx = 1004;
int n, c;
int a[mx];
vector<pair<int, int>> v;
map<int, int> mp_order, mp_cnt;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return mp_order[a.second] < mp_order[b.second];
    }
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp_cnt[a[i]]++; // 빈도 증가
        if (mp_order[a[i]] == 0) {
            mp_order[a[i]] = i + 1; // 순서 저장
        }
    }
    for (auto i : mp_cnt) { // 숫자와 빈도 저장
        v.push_back({ i.second, i.first });
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].first; ++j) {
            cout << v[i].second << ' ';
        }
    }
    cout << '\n';

    return 0;
}
