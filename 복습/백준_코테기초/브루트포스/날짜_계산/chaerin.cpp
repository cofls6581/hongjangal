/*
E,S,M의 범위를 활용해 조건을 만족하는 가장 최소값을 찾아야겠다는 생각을 했다.
처음에는 배수를 활용해 곱해지는 몫을 찾아 로직을 구상하려다가
나머지를 활용하는 게 더 간단한 방법으로 보여 나머지를 활용하는 방식을 사용했다.
*/

#include <iostream>
using namespace std;

int E, S, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    // input
    cin >> E >> S >> M;

    // logic
    int ans = 1;
    while (1) {
		if ((ans - E) % 15 == 0 && (ans - S) % 28 == 0 && (ans - M) % 19 == 0) { 
			break; 
		} 
		++ans;
	}

    // output
    cout << ans << endl;
    return 0;
}
