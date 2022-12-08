/*
'에라토스테네스의 체' 이용.
전체 수 다 할 필요 없이 MAX의 제곱근까지만 수행하면 됨.
안쪽 for문의 j도 i*i 부터 시작하면 됨. (이미 이전에 걸러짐)
*/
#include <iostream>
#define MAX 1000

using namespace std;

bool not_prime[MAX + 1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, cnt = 0, x;
    cin >> n;
    
    not_prime[1] = true;
    for (int i = 2; i * i <= MAX; i++) {
        if (not_prime[i]) continue;
        for (int j = i * i; j <= MAX; j += i) {
            not_prime[j] = true;
        }
    }
    while (n--) {
        cin >> x;
        if (!not_prime[x]) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
