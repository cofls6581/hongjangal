/*
나머지를 이용해서 품.
(year % 15)의 범위는 0 ~ 14 이기 때문에, (year % 15 == e) 와 같이 쓰면, e가 15인 경우는 처리할 수 없게 됨.
따라서, ((year - 1) % 15 + 1 == e) 로 예외 처리를 해줌.
*/
#include <iostream>
#define E 15
#define S 28
#define M 19

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int e, s, m;
    cin >> e >> s >> m;
    int year = 1;
    while (1) {
        if (((year - 1) % E + 1 == e) && ((year - 1) % S + 1 == s) && ((year - 1) % M + 1 == m)) {
            cout << year << '\n';
            break;
        }
        year++;
    }

    return 0;
}
