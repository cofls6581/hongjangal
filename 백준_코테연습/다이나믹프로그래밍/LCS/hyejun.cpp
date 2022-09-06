#include <iostream>
#include <algorithm>

using namespace std;

int d[1001][1001]; // d[i][j] : 첫번째 문자열이 i번째, 두번째 문자열이 j번째까지 있을 때 LCS의 길이

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // input
    string a, b;
    cin >> a >> b;

    // dp
    int a_size = a.size();
    int b_size = b.size();
    a = " " + a;
    b = " " + b;

    for (int i = 1; i <= a_size; i++) {
        for (int j = 1; j <= b_size; j++) {
            if (a[i] == b[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    // output
    cout << d[a_size][b_size] << '\n';
    return 0;
}
