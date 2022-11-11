/*
처음에는 a=1부터 시작해서 답을 찾을 때까지 a*10+1 하는 단순한 코드를 생각했는데
시간 초과가 나기 때문에 a % n = (a % n) % n 성질을 이용해서 풀어야 함.
반복문에 a를 넘길 때 그대로 넘기는 것이 아니라 n으로 % 연산해서 넘김.
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    while (cin >> n) {
        int a = 1;
        int cnt = 1;
        while (1) {
            if (a % n == 0) {
                cout << cnt << '\n';
                break;
            }
            a = a * 10 + 1;
            a %= n;
            cnt++;
        }
    }

    return 0;
}
