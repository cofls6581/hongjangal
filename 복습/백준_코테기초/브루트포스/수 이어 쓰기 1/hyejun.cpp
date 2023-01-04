/*
자릿수가 증가하는 경계값을 만날때까지 해당 자릿수를 계속해서 더함
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, totalDigit = 0;
    cin >> n;
    int digit = 1, boundary = 1;
    for (int i = 1; i <= n; i++) {
        if (i == boundary * 10) {
            boundary *= 10;
            digit++;
        }
        totalDigit += digit;
    }
    cout << totalDigit << '\n';

    return 0;
}
