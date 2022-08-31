#include <iostream>

using namespace std;

int value[101];
int d[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // input
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    // dp
    d[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = value[i]; j <= k; j++) {
            d[j] += d[j - value[i]];
        }
    }
    // output
    cout << d[k] << '\n';
    return 0;
}
