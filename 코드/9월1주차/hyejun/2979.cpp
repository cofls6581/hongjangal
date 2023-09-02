#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int a, b, c, mx, st[4], ed[4], cnt, ans;

int isParking(int time, int car) {
    return (time > st[car]) && (time <= ed[car]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> a >> b >> c;
    for (int i = 0; i < 3; ++i) {
        cin >> st[i] >> ed[i];
        if (ed[i] > mx) mx = ed[i];
    }
    for (int i = 1; i <= mx; ++i) {
        cnt = 0;
        for (int j = 0; j < 3; ++j) {
            cnt += isParking(i, j);
        }
        if (cnt == 1) ans += cnt * a;
        else if (cnt == 2) ans += cnt * b;
        else ans += cnt * c;
    }
    cout << ans << '\n';

    return 0;
}
