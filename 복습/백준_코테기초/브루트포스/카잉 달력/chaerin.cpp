/*
최소 공배수로 마지막 해를 구한 후 
x가 되는 년도 수들을 마지막 해까지 조건문을 걸어 돌리며
정답인 y가 되는 년도가 있는 찾는 로직
*/

#include <iostream>
using namespace std;

int t;
int m, n, x, y;
int ans;

int gcd(int a, int b){ //최대공약수
    if(b==0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){ //최소공배수
    return (a * b) / gcd(a, b);
}


int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    //input+logic+output
    cin >> t;
    while (t--) {
		cin >> m >> n >> x >> y;
        int lastYear = lcm(m, n); //마지막 해
        ans=-1; //정답인 케이스 없을 경우 -1 출력

        for (int i = x; i <= lastYear; i+=m){
            int ny = i % n;
            if(ny == 0)
                ny = n;

            if(ny == y){ //정답인 케이스
                ans = i;
                break;
            }
        }
		cout << ans << endl;
	}

    return 0;
}
