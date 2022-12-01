/*
1~N까지의 수  i를 N에 나눠 전체의 약수들에서 i의 개수를 구한 후 
그 갯수에 i를 곱해 약수의 합을 구하는 방식을 활용함.
처음에 ans를 int 자료형으로 선언해 틀린 후 long long으로 변경해 해결
*/

#include <iostream>
using namespace std;

int N;
long long ans=0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin >> N;
    //logic
    for (int i=1; i <=N; i++) {
		ans=ans+(N/i)*i;
	}
    //output
    cout<<ans<<'\n';
    return 0;
}
