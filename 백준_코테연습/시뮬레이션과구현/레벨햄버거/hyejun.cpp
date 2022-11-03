#include <iostream>

using namespace std;

long long d[51];
long long p[51];

long long go(int n, long long x) {
    if (n == 0) { // 레벨-0 버거
        if (x == 0) return 0;
        else return 1;
    }
    else if (x == 1) { // 번만 먹은 경우
        return 0;
    }
    else if (x <= 1 + d[n - 1]) { // (번 + 레벨 n-1 버거) 이내로 먹은 경우
        return go(n - 1, x - 1);
    }
    else if (x == 1 + d[n - 1] + 1) { // (번 + 레벨 n-1 버거 + 패티) 만큼 먹은 경우
        return p[n - 1] + 1;
    }
    else if (x <= 1 + d[n - 1] + 1 + d[n - 1]) { // (번 + 레벨 n-1 버거 + 패티 + 레벨 n-1 버거) 이내로 먹은 경우
        return p[n - 1] + 1 + go(n - 1, x - 1 - d[n - 1] - 1);
    }
    else { // 전체를 다 먹은 경우
        return p[n - 1] + 1 + p[n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // input
    int n;
    long long x;
    cin >> n >> x;

    // solution
    d[0] = 1;
    p[0] = 1;

    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }

    // output
    cout << go(n, x) << '\n';

    return 0;
}
