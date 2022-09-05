#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long d[101]; // 버튼을 총 N번 눌러서 출력할 수 있는 A의 최대 개수

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // input
    cin >> n;

    // dp
    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        for (int j = 1; j <= i - 2; j++) {
            d[i] = max(d[i], d[i - (j + 2)] * (j + 1));
        }
    }

    // output
    cout << d[n] << '\n';

    return 0;
}
