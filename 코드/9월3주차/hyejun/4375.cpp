#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    while (cin >> n) {
        int num = 1;
        int ans = 1;
        while (1) {
            if (num % n == 0) break;
            else {
                ans++;
                num = num * 10 + 1;
                num %= n;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
