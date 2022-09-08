#include <iostream>
#include <algorithm>

using namespace std;

int d[1001][1001]; // d[i][j] : 첫번째 문자열이 i번째, 두번째 문자열이 j번째까지 있을 때 LCS의 길이
int v[1001][1001]; // LCS 출력을 위한 case 분류

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
                v[i][j] = 1;
            }
            else {
                if (d[i - 1][j] < d[i][j - 1]) {
                    d[i][j] = d[i][j - 1];
                    v[i][j] = 2;
                }
                else {
                    d[i][j] = d[i - 1][j];
                    v[i][j] = 3;
                }
            }
        }
    }

    // output
    cout << d[a_size][b_size] << '\n';

    string ans = "";
    while (a_size > 0 && b_size > 0) {
        if (v[a_size][b_size] == 1) {
            ans += a[a_size];
            a_size--;
            b_size--;
        }
        else if (v[a_size][b_size] == 2) {
            b_size--;
        }
        else if (v[a_size][b_size] == 3) {
            a_size--;
        }
    }

    reverse(ans.begin(), ans.end()); // 역순이므로 순서 바꾸기
    cout << ans << '\n';

    return 0;
}
