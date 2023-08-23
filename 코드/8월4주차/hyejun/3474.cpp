#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int t, n, t_cnt, f_cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        cin >> n;
        t_cnt = 0; f_cnt = 0;
        for (int i = 2; i <= n; i *= 2) {
            t_cnt += n / i;
        }
        for (int i = 5; i <= n; i *= 5) {
            f_cnt += n / i;
        }
        cout << f_cnt << '\n';
    }

    return 0;
}
