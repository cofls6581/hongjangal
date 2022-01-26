#include <iostream>
#define MAX 11
using namespace std;

int d[MAX];

int solve(int n) {
    if (n == 1)
        return 1;
    if (d[n] != 0)
        return d[n];
    if (n == 2)
        return d[n] = solve(n - 1) + 1;
    if (n == 3)
        return d[n] = solve(n - 1) + solve(n - 2) + 1;
    else
        return d[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main() {
    int x;
    cin >> x;
    for (int i = 0; i < x; ++i) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}