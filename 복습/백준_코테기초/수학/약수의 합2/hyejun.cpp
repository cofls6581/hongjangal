/*
f(A)를 일일이 구하지 않고 g(x)를 구하는 방법을 생각함. n 이하의 자연수가 더해지는 개수는 
그 수의 배수들 중 n 이하인 것의 개수임. 따라서 'n을 해당 수로 나눈 몫 * 해당 수' 를 더함.
답의 범위가 클 것 같아서 long long 형을 사용함.
처음에 1과 자기자신은 따로 더하는 코드를 써서 덧셈에 실수가 있었음. 이후 for문으로 다 해결 가능함을 알고 수정함.
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (n / i) * i;
    }

    cout << ans << '\n';

    return 0;
}
