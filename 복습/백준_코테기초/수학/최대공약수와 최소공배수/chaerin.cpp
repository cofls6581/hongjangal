/*
최대공약수 구하는 공식이 존재하던게 기억나 구글링 통해 유클리드호제법 사용해 풀이함.
최소 공배수는 최대공약수를 이용해 값을 구함.
*/

#include <iostream>
using namespace std;

int a, b;
int gcd,lcm;

int getGcd (int a, int b) {
	int c;
	while (b != 0) {
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin >> a >> b;

    //logic
    gcd=getGcd(a,b);
    lcm = a*b/gcd;

    //output
    cout<<gcd<<'\n'<<lcm<<'\n';
    return 0;
}
