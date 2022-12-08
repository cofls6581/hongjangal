/*
'에라토스테네스의 체' 이용.
*/
#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

bool not_prime[MAX + 1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    not_prime[1] = true;
    for (int i = 2; i * i <= MAX; i++) {
        if (not_prime[i]) continue;
        for (int j = i * i; j <= MAX; j += i) {
            not_prime[j] = true;
        }
    }

    vector<int> prime;
    for (int i = 3; i <= MAX; i+=2) { // 홀수인 소수
        if (!not_prime[i]) {
            prime.push_back(i);
        }
    }

    int x, b, flag = 1;
    while (1) {
        cin >> x;
        if (x == 0) break;
        for (int i = 0; i < prime.size(); i++) {
            b = x - prime[i];
            if (!not_prime[b]) {
                cout << x << " = " << prime[i] << " + " << b << '\n';
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }

    return 0;
}
