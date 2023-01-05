/*
마지막 해(x, y의 최소공배수)까지 주기로 나눈 나머지를 검사함
y == n 인 경우에 대한 예외 처리 해줌
*/
#include <iostream>

using namespace std;

int get_gcd(int a, int b) {
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int get_lcm(int a, int b) {
    int gcd = get_gcd(a, b);
    return a * b / gcd;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    int m, n, x, y;
    cin >> t;
    while (t--) {
        cin >> m >> n >> x >> y;
        int lastYear = get_lcm(m, n);
        int k = -1;
        int i = 0, tmp;
        while (1) {
            tmp = m * i + x;
            if (tmp > lastYear) break;
            if ((tmp - 1) % n + 1 == y) {
                k = tmp;
            }
            i++;
        }
        cout << k << '\n';
    }

    return 0;
}
