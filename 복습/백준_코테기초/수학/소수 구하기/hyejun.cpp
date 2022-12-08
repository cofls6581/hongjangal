/*
'에라토스테네스의 체' 이용.
*/
#include <iostream>
#define MAX 1000000

using namespace std;

bool not_prime[MAX + 1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;
    
    not_prime[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if (not_prime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            not_prime[j] = true;
        }
    }
    
    for (int i = m; i <= n; i++) {
        if (!not_prime[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
