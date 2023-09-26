#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
// #pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
int n, d, p, maxDay = -1, totalMoney;
vector<pp> univ;
priority_queue<int> pq;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\input.txt", "r", stdin);
    // freopen("C:\\Users\\hyejunseo\\source\\repos\\algo\\algo\\output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p >> d;
        if (maxDay < d) maxDay = d;
        univ.push_back(make_pair(d, p));
    }
    sort(univ.begin(), univ.end(), greater<>()); // day 기준 내림차순
    int univIdx = 0;
    for (int day = maxDay; day > 0; --day) {
        while ((univIdx < n) && (univ[univIdx].first >= day)) pq.push(univ[univIdx++].second);
        if (pq.size()) {
            totalMoney += pq.top();
            pq.pop();
        }
    }
    cout << totalMoney << '\n';

    return 0;
}
