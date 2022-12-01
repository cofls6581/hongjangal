/*
1,2,3,.. 각 수의 배열 칸에 그 수를 더하는 방식으로 약수의 합을 먼저 구하고, 총합을 구함.
테케마다 답을 다시 구하면 시간 초과임.
*/
#include <iostream>
#define MAX 1000000

using namespace std;

long long d[MAX + 1];
long long g[MAX + 1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; i * j <= MAX; j++) {
            d[i * j] += i;
        }
    }
    for (int i = 1; i <= MAX; i++) {
        g[i] = g[i - 1] + d[i];
    }

    int t, x;
    cin >> t;
    while (t > 0) {
        cin >> x;
        cout << g[x] << '\n';
        t--;
    }

    return 0;
}
