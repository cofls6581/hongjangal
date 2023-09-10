#include <iostream>
#pragma warning(disable:4996)

using namespace std;

const int mx = 15004;
int n, m, a[mx], cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] + a[j] == m) cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}
