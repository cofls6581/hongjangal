#include <iostream>
#include <queue>
#include<set>
#include <tuple>
using namespace std;

const long long limit = 1000000000LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 변수
    long long s, t;
    cin >> s >> t;
    set<long long> check;
    queue<pair<long long, string>> q;

    // bfs
    q.push(make_pair(s, ""));
    check.insert(s);
    while (!q.empty()) {
        long long x;
        string str;
        tie(x, str) = q.front(); q.pop();
        if (x == t) { //정답인 경우
            if (str.length() == 0) {
                str = "0";
            }
            cout << str << '\n';
            return 0;
        }
        
        if (0 <= x * x && x * x <= limit && check.count(x * x) == 0) {
            q.push(make_pair(x * x, str + "*"));
            check.insert(x * x);
        }
        if (0 <= x + x && x + x <= limit && check.count(x + x) == 0) {
            q.push(make_pair(x + x, str + "+"));
            check.insert(x + x);
        }
        if (0 <= x - x && x - x <= limit && check.count(x - x) == 0) {
            q.push(make_pair(x - x, str + "-"));
            check.insert(x - x);
        }
        if (0 <= x / x && x / x <= limit && check.count(x / x) == 0) {
            q.push(make_pair(x / x, str + "/"));
            check.insert(x / x);
        }
    }
    cout << -1 << '\n';
    return 0;
}
