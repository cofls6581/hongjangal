#include <iostream>
using namespace std;

long long d[51];
long long p[51];

long long func(int n, long long x) {

    if (n == 0) { //패티 한장
        if (x == 0) return 0;
        else return 1;
    }
    else if (x == 1) { //햄버거번 한개
        return 0;
    }
    else if (x <= 1 + d[n - 1]) {
        return func(n - 1, x - 1);
    }
    else if (x == 2 + d[n - 1]) {
        return p[n - 1] + 1;
    }
    else if (x <= 1 + d[n - 1] + 1 + d[n - 1]) {
        return p[n - 1] + 1 + func(n - 1, x - 1 - d[n - 1] - 1);
    }
    else { // 전체 다
        return p[n - 1] + 1 + p[n - 1];
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;
    d[0] = 1; p[0] = 1;

    for (int i = 1; i <= n; ++i) {
        d[i] = d[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }

    cout << func(n, x) << '\n';
    return 0;
}
