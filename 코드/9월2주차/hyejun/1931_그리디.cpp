#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
int n, from, to, cnt = 1;
vector<pp> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> from >> to;
        v.push_back({ to,from });
    }
    sort(v.begin(), v.end());
    from = v[0].second;
    to = v[0].first;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i].second < to) continue; // 이전 회의가 안 끝난 경우
        from = v[i].second;
        to = v[i].first;
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}
