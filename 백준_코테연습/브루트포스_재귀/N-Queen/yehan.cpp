#include <iostream>
using namespace std;
bool a[15][15];
int n;
bool check_col[15]; // |
bool check_dig[40]; // 왼쪽 위 대각선
bool check_dig2[40]; // /

bool check(int row, int col) {
    // |
    if (check_col[col]) return false;
   
    // 왼쪽 위 대각선
    if (check_dig[row + col]) return false;
    // /
    if (check_dig2[row - col + n]) return false;

    return true;
}

int calc(int row) {
    if (row == n) return 1;

    int cnt = 0;
    for (int col = 0; col < n; col++) {
        if (check(row, col)) { // 퀸을 하나 놓을 때마다 검사 위치 체크
            // 퀸을 놓는다.
            check_dig[row + col] = true;
            check_dig2[row - col + n] = true;
            check_col[col] = true;
            a[row][col] = true;

            cnt += calc(row + 1);

            // 퀸을 놓지 않는다.
            check_dig[row + col] = false;
            check_dig2[row - col + n] = false;
            check_col[col] = false;
            a[row][col] = false;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cout << calc(0) << '\n';
    return 0;
}
