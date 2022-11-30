/*
최대공약수는 1에서 시작해서 수를 늘려가며 직접 나머지를 확인해서 구함.
최소공배수는 두 수의 곱을 최대공약수로 나누어서 구함.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;

    int gcd = 1; // 최대공약수
    int smaller = min(a, b);
    for (int i = 1; i <= smaller; i++) {
        if ((a % i == 0) && (b % i == 0)) {
            gcd = i;
        }
    }
    int lcm; // 최소공배수
    lcm = (a * b) / gcd;

    cout << gcd << '\n' << lcm << '\n';

    return 0;
}
