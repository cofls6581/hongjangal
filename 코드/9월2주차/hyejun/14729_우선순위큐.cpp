#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n;
priority_queue<double> pq;
vector<double> v;

int main(void) {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    double x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (pq.size() == 7) {
            pq.push(x);
            pq.pop();
        }
        else pq.push(x);
    }

    while (pq.size()) {
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(), v.end());

    for (double i : v) {
        printf("%.3lf\n", i);
    }

    return 0;
}
