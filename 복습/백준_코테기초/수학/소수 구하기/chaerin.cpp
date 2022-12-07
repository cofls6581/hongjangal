/*
문제에서 1 ≤ M ≤ N ≤ 1,000,000을 보고 범위를 조심해야겠다는 생각부터 들었다.
원래는 입력으로 받은 큰 수까지 1부터 하나씩 값을 돌며 배열에 미리 소수인지아닌지 정보를 저장한 후
해당 배열에서 필요한 인덱스 값들을 돌며 소수 값들을 찾아 출력했다.
InvalidNextSize 런타임에러가 발생했고 문제에 할당된 메모리를 초과해 사용해 발생한 에러였다.
로직을 봤으나 크게 최적화할 부분이 없었고 그렇다면 소수인지판별하는 prime 배열의 자료형을 바꿔야겠다는 생각이 들었다.
int형에서 bool형으로 변경했다.
*/

#include <iostream>
#include <vector>
using namespace std;

int N,M;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin>>N>>M;
    bool * prime=new bool[M+1];

    //logic
    prime[1]=1;
    for(int i=2;i<=M;i++) {
		if (prime[i]) continue;
		for (int j=i+i; j<=M; j+=i) {
			prime[j]=true;
		}
	}

    //output
    for(int i=N;i<=M;++i)
        if(!prime[i]) cout<<i<<'\n';
    return 0;
}
