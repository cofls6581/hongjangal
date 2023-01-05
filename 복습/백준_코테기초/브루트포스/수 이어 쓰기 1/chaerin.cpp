/*
처음엔 9,99,999,..와 같이 자릿가 바뀌는 경계값을 기준으로 
1부터 인풋 값까지 for문을 돌며 조건문으로 일일이 하나씩 자릿수 값을 더하는 로직을 생각했다.
비효율적이라는 생각이 들었고 아래와 같이 더 효율적인 방안의 로직으로 해결했다.
자릿수가 1인 수의 개수+자릿수가 2인 수의 개수+,,,
*/

#include <iostream>
using namespace std;

int n;
int ans = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //input
    cin >> n;
    //logic
    for (int i = 1; i <= n; i *= 10) {
		ans += n - i + 1;
	}
    //output
    cout << ans << '\n';
    return 0;
}
