/*
최대공약수를 구할 때 유클리드 호제법을 이용하는 것으로 수정함.
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;

    int gcd = get_gcd(a, b); // 최대공약수
    int lcm = (a * b) / gcd; // 최소공배수

    cout << gcd << '\n' << lcm << '\n';

    return 0;
}
